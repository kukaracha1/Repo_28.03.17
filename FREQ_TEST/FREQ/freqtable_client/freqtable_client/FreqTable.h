#pragma once

class FreqTable
{
public:

	virtual void SetTable(char[20]) = 0;
	virtual void AddTable(char[20]) = 0;
	virtual void PrintTable() = 0;
	virtual void Destroy() = 0;

};

typedef FreqTable* (__stdcall *PtrFreqTable)();