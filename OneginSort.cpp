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

void WriteFile (struct Text *text);

void MakeString (struct Text *text);

size_t DeleteSpaces (char *array);

int AlphabetOrderCMP (const void *arg1, const void *arg2);

void AlphabetOrderSort(struct Text *text);

int RhymeCMP (const void *arg1, const void *arg2);

void RhymeSort (struct Text *text);

int OriginalCMP (const void *arg1, const void *arg2);

void OriginalSort (struct Text *text);

void TestPrint (struct Text *text);

int main()
{
	struct Text hamlet;

	ReadFile(&hamlet);

	MakeString(&hamlet);

	AlphabetOrderSort(&hamlet);

	RhymeSort(&hamlet);

	WriteFile(&hamlet);

	OriginalSort(&hamlet);

	//TestPrint(&hamlet);

	//WriteFile(&hamlet);

	free(hamlet.buffer);
	free(hamlet.strings);

	return 0;
}

void ReadFile (struct Text *text)
{
	text->file_name = "hamlet.txt";

	text->size_of_file = 200000;

	text->buffer = (char*) calloc(text->size_of_file, sizeof(char));

	FILE *fp = NULL;

	fp = fopen(text->file_name, "r");

	int sz = fread(text->buffer, sizeof(char), text->size_of_file, fp);
	text->buffer[sz] = EOF;

	fclose(fp);
}

void WriteFile (struct Text *text)
{
	text->file_name = "hamlet.txt";

	FILE *fp = NULL;

	fp = fopen(text->file_name, "w");

	for (size_t i = 0; i < text->num_of_strings; i++)
		fprintf(fp, "%s\n", text->strings[i].ptr);
	printf("\n");
}

void MakeString (struct Text *text)
{
	text->num_of_strings = DeleteSpaces(text->buffer);

	text->strings = (struct String*) calloc(text->num_of_strings, 
		sizeof(struct String));

	char *string_ptr = text->buffer;
	char *newline_pos = NULL;
	int string_ctr = 0;

	while ((newline_pos = strchr (string_ptr, '\n')) || 
		(newline_pos = strchr (string_ptr, EOF)))
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
	int is_newline = true;
	int is_space = true;
	int num_of_strings = 0;
	for (i = 0, j = 0; array[i] != EOF; i++)
	{
		if (array[i] == '\n')
		{
			if(!is_newline && array[i + 1] != '\0')
			{
				array[j++] = array[i];
				is_newline = true;
				num_of_strings++;
			}
			else
				continue;
		}

		else if (isspace(array[i]))
		{
			if (!is_space && !is_newline)
			{
				array[j++] = array[i];
				is_space = true;
			}
			else
				continue;
		}
		else if (array[i] != '\0')
		{
			array[j++] = array[i];
			is_newline = false;
			is_space = false;
		}
	}
	array[j] = '\n';
	return num_of_strings + 1;
}

int AlphabetOrderCMP(const void *arg1, const void *arg2)
{
	struct String *str1 = (struct String *) arg1;
	struct String *str2 = (struct String *) arg2;

	char *ptr1 = str1->ptr;
	char *ptr2 = str2->ptr;

	while (!isalpha(*ptr1))
	{
		if(ptr1 <= str1->ptr + str1->len - 1)
			break;
		ptr1++;
	}

	while (!isalpha(*ptr2))
	{
		if(ptr2 <= str2->ptr + str2->len - 1)
			break;
		ptr2++;
	}

	return strcmp(ptr1, ptr2);
}

void AlphabetOrderSort(struct Text *text)
{
	qsort(text->strings, text->num_of_strings, sizeof (struct String), 
		AlphabetOrderCMP);
}

int RhymeCMP (const void *arg1, const void *arg2)
{
	struct String *str1 = (struct String *) arg1;
	struct String *str2 = (struct String *) arg2;

	char *ptr1 = str1->ptr + str1->len - 2;
	char *ptr2 = str2->ptr + str2->len - 2;

	// if (!isalpha(*ptr1))
	// 	ptr1--;

	// if (!isalpha(*ptr2))
	// 	ptr2--;

	while (!isalpha(*ptr1))
	{
		if (ptr1 <= str1->ptr)
			break;
		ptr1--;
	}

	while (!isalpha(*ptr2))
	{
		if (ptr2 <= str2->ptr)
			break;
		ptr2--;
	}

	while (*ptr1 == *ptr2)
	{
		if (ptr1 == str1->ptr && ptr2 == str2->ptr)
			return 0;
		ptr1--;
		ptr2--;
	}

	return *ptr1 - *ptr2;
}

void RhymeSort (struct Text *text)
{
	qsort(text->strings, text->num_of_strings, sizeof (struct String), 
		RhymeCMP);
}

int OriginalCMP (const void *arg1, const void *arg2)
{
	struct String *str1 = (struct String *) arg1;
	struct String *str2 = (struct String *) arg2;

	return str1->ptr - str2->ptr;
}

void OriginalSort (struct Text *text)
{
	qsort(text->strings, text->num_of_strings, sizeof (struct String), 
		OriginalCMP);
}

void TestPrint (struct Text *text)
{
	for (size_t i = 0; i < text->num_of_strings; i++)
		printf("%d\t%s\n", text->strings[i].len, text->strings[i].ptr);
	printf("\n");
}