#include <iostream>
#include <string>

using namespace std;

class printer {
	string * mas;
	string * statistics;
	int maxsize;
	int lenth;
public:
	printer() {
		mas = nullptr;
		statistics = nullptr;
		maxsize = 20;
		lenth = 0;
	}

	printer(int m)
	{
		//�������� ������
		maxsize = m;
		//������� �������
		string mas = new char[maxsize];
		string statistics = new char[maxsize];
		// ���������� ������� �����
		lenth = 0;
	}

	bool IsEmpty()
	{
		// ����?
		return lenth == 0;
	}

	string Extract()
	{
		// ���� � ������� ���� ��������, �� ���������� ���, 
		// ������� ����� ������ � �������� �������	
		if (!IsEmpty())
		{
			//��������� ������
			string temp = mas[0];
			string sttemp = statistics[0];


			//�������� ��� ��������
			for (int i = 1; i < lenth; i++)
				mas[i - 1] = mas[i];

			for (int i = 1; i < lenth; i++)
				sttemp[i - 1] = sttemp[i];

			//��������� ����������
			lenth--;

			//������� ������(�������)
			return (temp, sttemp);
		}

		else // ���� � ����� ��������� ���
			return "Empty";
	}

	void Clear()
	{
		// ����������� "�������" ������� 
		lenth = 0;
	}

	bool IsFull()
	{
		// �����?
		return lenth == maxsize;
	}

	int GetCount()
	{
		// ���������� �������������� � ����� ���������
		return lenth;
	}

	void Add(string c, string name)
	{
		// ���� � ������� ���� ��������� �����, �� ����������� ����������
		// �������� � ��������� ����� �������
		if (!IsFull()) {
			mas[lenth++] = c;

			/*char date[50] = {};

			time_t unixTime = time(nullptr);

			ctime_s(date, sizeof(date) / sizeof(date[0]), &unixTime);*/

			statistics[lenth++] = name;
		
		}
	}

	void Print() {
		for (int i = 0; i < lenth; i++) {
			cout << mas[i] << " - " << statistics[i] << endl;
		}
	}

	~printer() {
		delete[] mas;
		delete[] statistics;
	}
};


int main() {
	printer obj1;

	obj1.Add("HELLO", "Ivan");

	obj1.Print();
}