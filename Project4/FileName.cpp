#include<iostream>
using namespace std;

class Car
{
	char* model;
	int year;
	double price;
public:
	Car()
	{
		model = nullptr;
		year = 0;
		price = 0.0;
	}
	Car(const char* mod)
	{
		model = new char[strlen(mod) + 1];
		strcpy_s(model, strlen(mod) + 1, mod);
	}
	Car(const char* mod, int y, double pr) : Car(mod)  // делегирование
	{
		year = y;
		price = pr;
	}
	Car(const Car& obj) = delete;

	Car& operator=(const Car& obj) = delete;
	~Car() // 3
	{
		delete[]model;
	}

	const char* getModel()
	{
		return model;
	}
	int GetYear()
	{
		return year;
	}
	double GetPrice()
	{
		return price;
	}

	void SetModel(const char* mod)
	{
		if (model != nullptr)
			delete[] model;
		model = new char[strlen(mod) + 1];
		strcpy_s(model, strlen(mod) + 1, mod);
	}
	void SetYear(int y)
	{
		year = y;
	}
	void SetPrice(double pr)
	{
		price = pr;
	}


	Car(Car&& b) // move semantics  (семантика переноса) конструктор переноса
	{
		cout << "Move Constructor\n";
		model = b.model;
		b.model = nullptr; //  оставляем указатель внутри B, в согласованном состоянии(например для вызова деструктора)
		year = b.year;
		b.year = 0;
		price = b.price;
		b.price = 0;
	}
};
ostream& operator<<(ostream& os, Car& obj)
{
	os << obj.getModel() << "\t" << obj.GetYear() << "\t" << obj.GetPrice() << endl;
	return os;
}
istream& operator>>(istream& is, Car& obj)
{
	char buff[20];
	cout << "Enter model -> ";
	is >> buff;
	obj.SetModel(buff);
	int y;
	double pr;
	cout << "Enter year -> ";
	is >> y;
	obj.SetYear(y);
	cout << "Enter price -> ";
	is >> pr;
	obj.SetPrice(pr);
	return is;
}

int main()
{
	Car obj1("Audi A5", 2023, 50000);

	Car obj2 = move(obj1);

	if (obj1.getModel() == nullptr) {
		cout << "obj1 nullptr";
	}

	cout << endl << obj2;
}