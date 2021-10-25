#include "OneginSort.h"

void Greetings ();

void Goodbye ();

int main(int argc, char* argv[])
{
	Text text {};

	Greetings ();

    if (GetFileNames(&text, argc, argv) == 1)
    {
        printf("Error: wrong name of file(s)");
        return 1;
    }

	ReadFromFile(&text);

	MakeString(&text);

	FILE *output_file = OpenFileWrite(&text);

	if (!output_file)
	{
		printf("Output file ERROR\n");
		return 1;
	}

	AlphabetOrderSort(&text);
	WriteToFile(&text, output_file);

	RhymeSort(&text);
	WriteToFile(&text, output_file);

	OriginalSort(&text);
	WriteToFile(&text, output_file);

	CloseFile(output_file);

	MemoryFree(&text); //TODO убивать структуру

	Goodbye(); //TODO сделать проверки на ошибки

	return 0;
}

void Greetings ()
{
	printf("\nHello. This program can sort strings of text.\n");
}

void Goodbye ()
{
	printf("\nYour text is sorted.\n");
}