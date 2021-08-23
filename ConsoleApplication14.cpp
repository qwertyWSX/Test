#include <iostream>
#include <time.h>
using namespace std;

class List
{
	//asdf
	struct Node
	{
		Node* Next;
		Node* Prev;
		int Data;
	};
	
	Node* Start;
	Node* End;
	int Size;

	
public:
	List()
	{
		Size = 0;
		Start = nullptr;
		End = nullptr;
	}
	~List()
	{
		Clear();
	}

	int GetSize() {return Size;}
	void PushBack(int data)
	{
		Node* temp = End;
		End = new Node;
		End->Data = data;
		End->Next = nullptr;
		End->Prev = temp;
		if (temp!=nullptr) temp->Next = End;
		if (Start == nullptr) Start = End;
		Size++;
	}
	void PushTop(int data)
	{
		Node* temp = Start;
		Start = new Node;
		Start->Data = data;
		Start->Next = temp;
		Start->Prev = nullptr;
		if (temp != nullptr) temp->Prev = Start;
		if (End == nullptr) End = Start;
		Size++;
	}
	void Insert(int index, int data)
	{

	}
	void Erase(int index)
	{

	}
	void Clear()
	{

	}

	friend ostream& operator << (ostream &out, const List &list);
};

ostream& operator << (ostream& out, const List& list)
{
	List::Node* temp = list.Start;
	while (temp->Next != nullptr)
	{
		out << temp->Data << " ";
		temp = temp->Next;
	}
	out << temp->Data;
	return out;
}



int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	List L1;


	for (int i = 0; i < 2; i++)
	{
		L1.PushBack(1 + rand() % 9);
	}	
	cout << L1 << endl;
	for (int i = 0; i < 2; i++)
	{
		L1.PushTop(1 + rand() % 9);
	}
	cout << L1 << endl;
	for (int i = 0; i < 2; i++)
	{
		L1.PushBack(1 + rand() % 9);
	}
	cout << L1 << endl;
	return 0;
}