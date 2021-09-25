#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cassert>

struct String
{
	int len;
	char *ptr;
};

struct Text
{
	const char *file_name;
	size_t size_of_file;
	char *buffer;
	size_t num_of_strings;
	struct String *strings;
};

void ReadFile (struct Text *text);

void MakeString (struct Text *text);

size_t DeleteSpaces (char *array);

int IsSpaceOrTab (char ch);

int AlphabetOrderCMP(const void *arg1, const void *arg2);

void AlphabetOrderSort(struct Text *text);

int main()
{
	struct Text hamlet;

	ReadFile(&hamlet);

	MakeString(&hamlet);

	AlphabetOrderSort(&hamlet);

	for (size_t i = 0; i < hamlet.num_of_strings; i++)
		printf("%d\t%s\n", hamlet.strings[i].len, hamlet.strings[i].ptr);
	printf("\n\n");

	free(hamlet.buffer);
	free(hamlet.strings);

	return 0;
}

void ReadFile (struct Text *text)
{
	text->file_name = "hamlet.txt";

	text->size_of_file = 200000;

	text->buffer = (char*) calloc(text->size_of_file, sizeof(char));

	FILE *fp;

	fp = fopen(text->file_name, "r");

	int sz = fread(text->buffer, sizeof(char), text->size_of_file, fp);
	text->buffer[sz] = EOF;

	fclose(fp);
}

void MakeString (struct Text *text)
{
	text->num_of_strings = DeleteSpaces(text->buffer);

	text->strings = (struct String*) calloc(text->num_of_strings, sizeof(struct String));

	char *string_ptr = text->buffer;
	char *newline_pos = NULL;
	int string_ctr = 0;

	while ((newline_pos = strchr (string_ptr, '\n')) || (newline_pos = strchr (string_ptr, EOF)))
	{
		if((long unsigned int)string_ctr >= text->num_of_strings) 
		{
			*newline_pos = '\0';
			break;
		}
		*newline_pos = '\0';

		text->strings[string_ctr].ptr = string_ptr;
		text->strings[string_ctr].len = newline_pos - string_ptr + 1;

		string_ptr = newline_pos + 1;

		string_ctr++;
	}
}

size_t DeleteSpaces (char *array)
{	
	int i, j;
	int is_newline = false;
	int num_of_strings = 0;
	for (i = 0, j = 0; array[i] != EOF; i++)
	{
		if (array[i] == '\n')
		{
			if(array[i + 1] != '\n' && array[i + 1] != 0)
			{
				array[j++] = array[i];
				is_newline = true;
				num_of_strings++;
			}
			else
				continue;
		}

		else if (IsSpaceOrTab(array[i]))
		{
			if (!isspace(array[i + 1]) && !is_newline)
				array[j++] = array[i];
			else
				continue;
		}
		else if(array[i] != 0)
		{
			array[j++] = array[i];
			is_newline = false;
		}
	}
	array[j] = '\n';
	return num_of_strings + 1;
}

int IsSpaceOrTab (char ch)
{
	return (ch == ' ' || ch == '\t') ? 1 : 0;
}

int AlphabetOrderCMP(const void *arg1, const void *arg2)
{
	struct String *str1 = (struct String *) arg1;
	struct String *str2 = (struct String *) arg2;

	char *ptr1 = str1->ptr;
	char *ptr2 = str2->ptr;

	while (!isalpha(*ptr1))
		ptr1++;

	while (!isalpha(*ptr2))
		ptr2++;

	return strcmp(ptr1, ptr2);
}

void AlphabetOrderSort(struct Text *text)
{
	qsort(text->strings, text->num_of_strings, sizeof (struct String), AlphabetOrderCMP);
}