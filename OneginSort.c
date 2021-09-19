#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_OF_FILE 200000

void ReadFile (char* buffer, const char* file_name, size_t size_of_file);


int main()
{
	char *buffer = (char*) calloc(SIZE_OF_FILE, sizeof(char));

	ReadFile(buffer,"hamlet.txt" ,SIZE_OF_FILE);

	for (int i = 0; buffer[i] != EOF; i++)
		printf("%c", buffer[i]);
}

void ReadFile (char* buffer, const char *file_name, size_t size_of_file)
{
	FILE *fp;

	fp = fopen(file_name, "r");

	fread(buffer, sizeof(char), size_of_file, fp);
	buffer[size_of_file + 1] = EOF;

	fclose(fp);	
}