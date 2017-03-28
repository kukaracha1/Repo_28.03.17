#include <func.h>

class FactoryTest
{
public:
	unsigned int count[256];	// ������ � ����� ���������� ��������  � ������
	float frequent[256];	// ������� ��������

	int length;		// ����� ���������� �������� � ������

	void Clear()
	{
		// ��������� �������
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

	// ����������� ������� ��� ��������
	void Frequent()
	{
		for (size_t i = 0; i < 256; i++)
		{
			// ������� �������
			frequent[i] = count[i] / length;
		}
	}

	void getCount(string text)
	{
		// ������� ��������� ���������
		for (size_t i = 0; i < text.length(); i++)
		{
			// �� ��������� ����������� ������� �������
			count[(unsigned char)text[i]]++;		// text[i] - ������ � ������, ������������� � ���
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

	string text = "hello world. ������ ���";	// �����, ��������� �� �����
	FactoryTest f;
	f.createTable(text);
	f.viewTable();
	f.addToTable(text);
	f.viewTable();
	pas();
}