#include "OneginSort.h"

void Greetings ();

void Goodbye ();

int main()
{
	struct Text input_text {};

	Greetings ();

	ReadFromFile(&input_text);

	MakeString(&input_text);

	FILE *output_file = OpenFileWrite();

	if (!output_file)
	{
		printf("Output file ERROR\n");
		return 1;
	}

	AlphabetOrderSort(&input_text);
	WriteToFile(&input_text, output_file);

	RhymeSort(&input_text);
	WriteToFile(&input_text, output_file);

	OriginalSort(&input_text);
	WriteToFile(&input_text, output_file);

	CloseFile(output_file);

	MemoryFree(&input_text); //TODO убивать структуру

	Goodbye(); //TODO сделать проверки на ошибки

	return 0;
}

void Greetings ()
{
	printf("Hello. This program can sort strings of text.\n\n");
}

void Goodbye ()
{
	printf("Your text is sorted.\n\n");
}