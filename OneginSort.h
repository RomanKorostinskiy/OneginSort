#include <stdio.h> //TODO разделить программу на отдельные файлы
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cassert>

enum File_errors
{
	WRONG_INPUT_FILE,
};

struct String
{
	int len;
	char *ptr;
};

struct Text
{
	char *input_file_name;
	size_t size_of_input_file;
	char *buffer;
	size_t num_of_strings;
	struct String *strings;
};

int ReadFromFile (struct Text *text);

size_t GetSizeOfFile (FILE* fp);

void WriteToFile (struct Text *text, FILE *fp);

FILE* OpenFileWrite ();

void CloseFile (FILE *fp);

void MakeString (struct Text *text);

size_t DeleteSpaces (char *array);

void MemoryFree (struct Text *text);

int AlphabetOrderCMP (const void *arg1, const void *arg2);

void AlphabetOrderSort(struct Text *text);

int RhymeCMP (const void *arg1, const void *arg2);

void RhymeSort (struct Text *text);

int OriginalCMP (const void *arg1, const void *arg2);

void OriginalSort (struct Text *text);
