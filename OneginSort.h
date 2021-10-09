#include <stdio.h> //TODO разделить программу на отдельные файлы
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cassert>

enum File_errors
{
	WRONG_INPUT_FILE = 6,
};

typedef struct String_t
{
	int len = 0;
	char *ptr = nullptr;
}String;

typedef struct Text_t
{
	char *input_file_name = nullptr;
	size_t size_of_input_file = 0;
	char *buffer = nullptr;
	size_t num_of_strings = 0;
	String *strings = nullptr;
} Text;

int ReadFromFile (Text *text);

size_t GetSizeOfFile (FILE* fp);

void WriteToFile (Text *text, FILE *fp);

FILE* OpenFileWrite ();

void CloseFile (FILE *fp);

void MakeString (Text *text);

size_t DeleteSpaces (char *array);

void MemoryFree (Text *text);

int AlphabetOrderCMP (const void *arg1, const void *arg2);

void AlphabetOrderSort(Text *text);

int RhymeCMP (const void *arg1, const void *arg2);

void RhymeSort (Text *text);

int OriginalCMP (const void *arg1, const void *arg2);

void OriginalSort (Text *text);
