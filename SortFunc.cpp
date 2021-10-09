#include "OneginSort.h"

int AlphabetOrderCMP(const void *arg1, const void *arg2)
{
	struct String *str1 = (struct String *) arg1;
	struct String *str2 = (struct String *) arg2;

	char *ptr1 = str1->ptr;
	char *ptr2 = str2->ptr;

	while (!isalpha(*ptr1))
	{
		if(ptr1 >= str1->ptr + str1->len - 1)
			break;
		ptr1++;
	}

	while (!isalpha(*ptr2))
	{
		if(ptr2 >= str2->ptr + str2->len - 1)
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