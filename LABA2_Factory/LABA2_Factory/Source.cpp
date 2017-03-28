#include <iostream>
#include <limits>
#include <string>

using namespace std;

const size_t CHAR_TYPE_SIZE = numeric_limits<unsigned char>::max() + 1;

char getMostUsedChar(string text)
{
	// Подготовка счетчиков символов.
	unsigned int count[CHAR_TYPE_SIZE];
	for (size_t i = 0; i < CHAR_TYPE_SIZE; ++i)
	{
		count[i] = 0;
	}

	// Подсчет символов в тексте.
	for (unsigned char c : text)
	{
		++count[c];
	}

	// Определение индекса наиболее часто встречающегося символа.
	size_t index = 0;
	for (size_t i = 1; i < CHAR_TYPE_SIZE; ++i)
	{
		if (count[i] > count[index])
		{
			index = i;
		}
	}

	return static_cast<char>(index);
}

int main()
{
	string text;

	cout << "Text: ";
	getline(cin, text);

	cout << "Most used char: " << getMostUsedChar(text) << endl;

	system("pause");

	return 0;
}