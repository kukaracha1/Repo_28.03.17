#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <io.h>
#include <string.h>
#include <func.h>

#include "freqtable.h"
using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 

	const char* libraryName = "frequency_table.dll";
	const char* functionName = "GetFreqTable";

	HMODULE hm = LoadLibrary(libraryName);
	if (!hm)
	{
		printf("%s not found; bye.\n", libraryName);
		pas();
		return 0;
	}
	PtrFreqTable GetFreqTable = (PtrFreqTable)GetProcAddress(hm, functionName);
	if (!GetFreqTable)
	{
		printf("Function \'%s\' not found in %s; bye.\n", functionName, libraryName);
		pas(); 
		return 0;
	}

	FreqTable *f = GetFreqTable();

	if (f)
	{
		char name[20];
		cout << "File name: ";
		cin >> name;
		cout << name << endl;
		f->SetTable(name);
		f->Destroy();
	/*	FILE * file;
		file = fopen(name, "rb");
		if (file != NULL)
		{
			fseek(file, 0, SEEK_END);
			size_t size = ftell(file);
			fseek(file, 0, SEEK_SET);
			char *buff = new char[size];
			fread(buff, 1, size, file); //считывание строки



			FILE * file_ = fopen("cod.txt", "w");
			fwrite(buff, 1, size, file_);
			fclose(file_);
			fclose(file);
			delete[]buff;
		}
		else
		{
			cout << "Sorry, error";
		}*/
	}
	else
	{
		printf("Error creating object!\n");
		pas();
	}
	pas();
	_getch();
	return 0;
}
