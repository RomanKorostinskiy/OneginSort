#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const int SIZE_OF_FILE = 200000;

enum bool{
	false,
	true
};

struct Strings
{
	int len;
	char *ptr;
};

struct Text
{
	char *file_name;
	size_t size_of_file;
	char *buffer;
	size_t num_of_strings;
	struct Strings *file_strings;
};

void MakeTextInfo (struct Text *text);

void ReadFile (char *buffer, const char *file_name, size_t size_of_file);

void MakeString (char *array, struct Strings* strings);

void DeleteSpaces (char *array);

int IsSpaceOrTab (char ch);


int main()
{
	struct Text hamlet;
	MakeTextInfo (&hamlet);

	char *buffer = (char*) calloc(SIZE_OF_FILE, sizeof(char));

	ReadFile(buffer, hamlet.file_name ,SIZE_OF_FILE); //добавиь возможность вводить название файла с клавиатуры

	struct Strings *file_Strings = (struct Strings*) calloc(SIZE_OF_FILE, sizeof(struct Strings));

	MakeString(buffer, file_Strings);

	free(buffer);
}

void MakeTextInfo (struct Text *text) //сделать скан всех полей text
{
	text->file_name = "hamlet.txt";
	text->size_of_file = 200000;
	text->buffer = (char*) calloc(text->size_of_file, sizeof(char));
}

void ReadFile (char *buffer, const char *file_name, size_t size_of_file) //добавить информацию об открытии файла
{
	FILE *fp;

	fp = fopen(file_name, "r");

	fread(buffer, sizeof(char), size_of_file, fp);
	buffer[size_of_file + 1] = EOF;

	fclose(fp);	
}

void MakeString (char *array, struct Strings* Strings)
{

	DeleteSpaces(array);

	size_t newline_pos;

/////////////////////////
	for (int i = 0; array[i] != EOF; i++)
		printf("%c", array[i]);
/////////////////////////

}

void DeleteSpaces (char *array)
{
	int i, j;
	int is_newline = false;
	for (i = 0, j = 0; array[i] != EOF; i++)
	{
		if (array[i] == '\n')
		{
			if(array[i + 1] != '\n')
			{
				array[j++] = array[i];
				is_newline = true;
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
}

int IsSpaceOrTab (char ch)
{
	if (ch == ' ' || ch == '\t')
		return 1;
	else
		return 0;
}