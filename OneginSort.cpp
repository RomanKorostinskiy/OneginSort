/* Проблемы:
- считывается лишний \n
- в MakeString не дедтектируется eof в цикле
- MakeString не работает впринципе*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const int SIZE_OF_FILE = 200000;

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
	struct String *file_strings;
};

void ReadFile (struct Text *text);

void MakeString (struct Text *text);

size_t DeleteSpaces (char *array);

int IsSpaceOrTab (char ch);


int main()
{
	struct Text hamlet;

	ReadFile(&hamlet); //добавиь возможность вводить название файла с клавиатуры

	MakeString(&hamlet);

	free(hamlet.buffer);
	free(hamlet.file_strings);
}

void ReadFile (struct Text *text) //добавить информацию об открытии файла
{
	text->file_name = "hamlet.txt";

	text->size_of_file = 200000;

	text->buffer = (char*) calloc(text->size_of_file + 1, sizeof(char));

	FILE *fp;

	fp = fopen(text->file_name, "r");

	fread(text->buffer, sizeof(char), text->size_of_file, fp);
	text->buffer[text->size_of_file] = EOF;

	fclose(fp);	
}

void MakeString (struct Text *text)
{
	text->num_of_strings = DeleteSpaces(text->buffer);

	text->file_strings = (struct String*) calloc(text->num_of_strings, sizeof(struct String));

	char *string_ptr = text->buffer;
	char *newline_pos = NULL;
	int string_ctr = 0;

	while ((newline_pos = strchr (string_ptr, '\n')))
	{
		*newline_pos = '\0'; //

		text->file_strings[string_ctr].ptr = string_ptr;
		text->file_strings[string_ctr].len = newline_pos - string_ptr + 1;

		string_ptr = newline_pos + 1;	

		string_ctr++;
	}

/////////////////////////
	for (size_t i = 0; i < text->num_of_strings; i++)
		printf("%s\t%d\n", text->file_strings[i].ptr, text->file_strings[i].len);
/////////////////////////
	//for (int i = 0; text->buffer[i] != EOF; i++)
		//printf("%c", text->buffer[i]);
	printf("\nnum_of_strings =  %ld , %d\n", text->num_of_strings, string_ctr + 1);
/////////////////////////

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
			if(array[i + 1] != '\n' && array[i + 1] != EOF) //считывает последний /n перед EOF
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
		else
		{
			array[j++] = array[i];
			is_newline = false;
		}
	}

	array[j] = EOF;

	return num_of_strings + 1;
}

int IsSpaceOrTab (char ch)
{
	if (ch == ' ' || ch == '\t')
		return 1;
	else
		return 0;
}