#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "freqtable.h"

class FreqTableImplementation : public FreqTable
{
public:

	FreqTableImplementation()   {}

	virtual void SetTable(char name[20])
	{
		int chh;
		int k = 0;
		int kk = 0;
		int kolvo[256] = { 0 };
		char symbols[256] = { 0 };
		float freq[256] = { 0 };
		float summ = 0;
		FILE *f = fopen(name, "rb");
		if (f == NULL)
		{
			printf("Ошибка!");
		}

		/*СЧИТЫВАНИЕ ИЗ ФАЙЛА*/
		while ((chh = fgetc(f)) != EOF)
		{
			for (int j = 0; j<256; j++)
			{
				if (chh == symbols[j])
				{
					kolvo[j]++;
					kk++;
					break;
				}
				if (symbols[j] == 0)
				{
					symbols[j] = (char)chh;
					kolvo[j] = 1;
					k++; kk++;
					break;
				}
			}
		}

		/*ЧАСТОТА*/
		for (int i = 0; i<k; i++)
			freq[i] = (float)kolvo[i] / kk;


		printf("\nТаблица частот:\n");
		for (int i = 0; i<k; i++)
		{
			summ += freq[i];
			printf("Код= %d \tЧастота= %f\tСимвол= %c\t\n", symbols[i], freq[i],symbols[i]);
		}
		printf("\nКол-во символов= %d\tСуммарная частота= %f\n", kk, summ);


	}
	virtual void AddTable(char[20])
	{

	}
	virtual void PrintTable()
	{

	}
	virtual void Destroy()
	{
		delete this;
	}

private:
	char name[20];
};

extern "C"
FreqTable* __stdcall GetFreqTable()
{
	return new FreqTableImplementation;
}