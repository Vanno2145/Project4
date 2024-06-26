#include <iostream>
using namespace std;


struct Element
{
    // ������
    char data;
    // ����� ���������� �������� ������
    Element* Next;
};

// ����������� ������
class List
{
    // ����� ��������� �������� ������
    Element* Head;
    // ����� ��������� �������� ������
    Element* Tail;
    // ���������� ��������� ������
    int Count;

public:
    // �����������
    List();
    // ����������
    ~List();

    // ���������� �������� � ������
    // (����� ������� ���������� ���������)
    void Add(char data);

    // �������� �������� ������
    // (��������� �������� �������)
    void Del();
    // �������� ����� ������
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

    // ���������� ����������� ������
    // (���������� ���������� � ��������� ��������)
    void Print();

    // ��������� ���������� ���������, ����������� � ������
    int GetCount();
};

List::List()
{
    // ���������� ������ ����
    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{
    // ����� ������� ��������
    DelAll();
}

int List::GetCount()
{
    // ���������� ���������� ���������
    return Count;
}

void List::Add(char data)
{
    // �������� ������ ��������
    Element* temp = new Element;

    // ���������� �������
    temp->data = data;
    // ��������� ������� �����������
    temp->Next = NULL;
    // ����� ������� ���������� ��������� ��������� ������
    // ���� �� �� ������ �����������
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    // ����� ������� ���������� ������������
    // ���� �� ������ �����������
    else {
        Head = Tail = temp;
    }
}

void List::Del()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ������������� ������ �� ��������� �������
    Head = Head->Next;
    // ������� ������ �������� �������
    delete temp;
}

void List::DelAll()
{
    // ���� ��� ���� ��������
    while (Head != 0)
        // ������� �������� �� ������
        Del();
}

void List::Print()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ���� ��� ���� ��������
    while (temp != 0)
    {
        // ������� ������
        cout << temp->data << " ";
        // ��������� �� ��������� �������
        temp = temp->Next;
    }

    cout << "\n\n";
}



// �������� ������
void main()
{
    // ������� ������ ������ List
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