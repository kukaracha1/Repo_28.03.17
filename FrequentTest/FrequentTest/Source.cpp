#include <func.h>

class FactoryTest
{
public:
	unsigned int count[256];	// массив с число конкретных символов  в тексте
	float frequent[256];	// частоты символов

	int length;		// общее количество символов в тексте

	void Clear()
	{
		// обнуление массива
		for (size_t i = 0; i < 256; i++)
		{
			count[i] = 0;
			frequent[i] = 0;
		}
		length = 0;
	}

	FactoryTest()
	{
		Clear();
	}

	// высчитывает частоты для символов
	void Frequent()
	{
		for (size_t i = 0; i < 256; i++)
		{
			// частота символа
			frequent[i] = count[i] / length;
		}
	}

	void getCount(string text)
	{
		// подсчет количесва симоволов
		for (size_t i = 0; i < text.length(); i++)
		{
			// не правильно преобразует русские символы
			count[(unsigned char)text[i]]++;		// text[i] - символ в строке, преобразуется в инт
		}



		length += text.length();
	}

	void createTable(string text)
	{

		Clear();

		addToTable(text);

	}

	void addToTable(string text)
	{
		getCount(text);

		Frequent();
	}

	void viewTable()
	{
		for (size_t i = 0; i < 256; i++)
		{
			if (count[i] != 0)
				cout << (char)i << "\t" << count[i] << endl;
		}
		endl("-------------");
	}

	

};

void main()
{
	lang();

	string text = "hello world. привет мир";	// текст, считанный из файла
	FactoryTest f;
	f.createTable(text);
	f.viewTable();
	f.addToTable(text);
	f.viewTable();
	pas();
}