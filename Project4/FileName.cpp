#include <iostream>
using namespace std;


struct Element
{
    // Данные
    char data;
    // Адрес следующего элемента списка
    Element* Next;
};

// Односвязный список
class List
{
    // Адрес головного элемента списка
    Element* Head;
    // Адрес головного элемента списка
    Element* Tail;
    // Количество элементов списка
    int Count;

public:
    // Конструктор
    List();
    // Деструктор
    ~List();

    // Добавление элемента в список
    // (Новый элемент становится последним)
    void Add(char data);

    // Удаление элемента списка
    // (Удаляется головной элемент)
    void Del();
    // Удаление всего списка
    void DelAll();

    void Addindex(char c, int num) {
        int i = 1;
        Element* temp = Head;
        while (i < num)
        {
            temp = temp->Next;
            i++;
        }
        Element* nElement = new Element;
        nElement->data = c;

        nElement->Next = temp->Next;
        temp->Next = nElement;
    }

    void Delindex(int num) {
        int i = 1;
        Element* temp = Head;
        Element* del;
        while (i < num)
        {
            temp = temp->Next; 
            i++;
            
        }
        
        del = temp->Next;

        temp->Next = del -> Next;
        delete del;

    }

    void Search(char c) {
        
        Element* temp = Head;
        int index = 0;
        while (true) {
            if (temp->data == c) {
                cout << "data: " << temp->data << "  index: " << index << endl;
                break;
            }
            else {
                temp = temp->Next;
                index++;
                continue;
            }
            
        }
    }

    // Распечатка содержимого списка
    // (Распечатка начинается с головного элемента)
    void Print();

    // Получение количества элементов, находящихся в списке
    int GetCount();
};

List::List()
{
    // Изначально список пуст
    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{
    // Вызов функции удаления
    DelAll();
}

int List::GetCount()
{
    // Возвращаем количество элементов
    return Count;
}

void List::Add(char data)
{
    // создание нового элемента
    Element* temp = new Element;

    // заполнение данными
    temp->data = data;
    // следующий элемент отсутствует
    temp->Next = NULL;
    // новый элемент становится последним элементом списка
    // если он не первый добавленный
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    // новый элемент становится единственным
    // если он первый добавленный
    else {
        Head = Tail = temp;
    }
}

void List::Del()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // перебрасываем голову на следующий элемент
    Head = Head->Next;
    // удаляем бывший головной элемент
    delete temp;
}

void List::DelAll()
{
    // Пока еще есть элементы
    while (Head != 0)
        // Удаляем элементы по одному
        Del();
}

void List::Print()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // Пока еще есть элементы
    while (temp != 0)
    {
        // Выводим данные
        cout << temp->data << " ";
        // Переходим на следующий элемент
        temp = temp->Next;
    }

    cout << "\n\n";
}



// Тестовый пример
void main()
{
    // Создаем объект класса List
    List lst;

    lst.Add('H');
    lst.Add('e');
    lst.Add('l');
    lst.Add('l');
    lst.Add('o');
    lst.Addindex('X', 2);
    lst.Delindex(2);
    lst.Print();
    lst.Search('l');
}