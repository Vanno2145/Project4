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
		//получаем размер
		maxsize = m;
		//создаем очередь
		string mas = new char[maxsize];
		string statistics = new char[maxsize];
		// Изначально очередь пуста
		lenth = 0;
	}

	bool IsEmpty()
	{
		// Пуст?
		return lenth == 0;
	}

	string Extract()
	{
		// Если в очереди есть элементы, то возвращаем тот, 
		// который вошел первым и сдвигаем очередь	
		if (!IsEmpty())
		{
			//запомнить первый
			string temp = mas[0];
			string sttemp = statistics[0];


			//сдвинуть все элементы
			for (int i = 1; i < lenth; i++)
				mas[i - 1] = mas[i];

			for (int i = 1; i < lenth; i++)
				sttemp[i - 1] = sttemp[i];

			//уменьшить количество
			lenth--;

			//вернуть первый(нулевой)
			return (temp, sttemp);
		}

		else // Если в стеке элементов нет
			return "Empty";
	}

	void Clear()
	{
		// Эффективная "очистка" очереди 
		lenth = 0;
	}

	bool IsFull()
	{
		// Полон?
		return lenth == maxsize;
	}

	int GetCount()
	{
		// Количество присутствующих в стеке элементов
		return lenth;
	}

	void Add(string c, string name)
	{
		// Если в очереди есть свободное место, то увеличиваем количество
		// значений и вставляем новый элемент
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