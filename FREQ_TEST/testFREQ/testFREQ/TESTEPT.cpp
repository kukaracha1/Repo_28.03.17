#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char name[20] = "text.txt"; 
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
		printf("������!");
	}

	/*���������� �� �����*/
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

	/*�������*/
	for (int i = 0; i<k; i++)
		freq[i] = (float)kolvo[i] / kk;

	
	printf("\n������� ������:\n");
	for (int i = 0; i<k; i++)
	{
		summ += freq[i];
		printf("���= %d \t�������= %f\t������= %c\t\n", symbols[i], freq[i], symbols[i]);
	}
	printf("\n���-�� ��������= %d\t��������� �������= %f\n", kk, summ);

	getch();
}