#include <iostream>
#include<cstring>
using namespace std;

template<typename T>
class List
{
public:
	struct Node
	{
		T data;
		Node* prev;
		Node* next;

		Node(T data)
		{
			this->data = data;
			prev = next = nullptr;
		}
	};
	Node* head;
	Node* tail;
	int index;

public:
	List()
	{
		head = tail = nullptr;
	}
	Node* push_front(T data)
	{
		Node* ptr = new Node(data);

		ptr->next = head;
		if (head != nullptr)
		{
			head->prev = ptr;
		}
		if (tail == nullptr)
		{
			tail = ptr;
		}
		head = ptr;
		return ptr;
	}


	Node* push_back(T data)
	{
		Node* ptr = new Node(data);

		ptr->prev = tail;
		if (tail != nullptr)
		{
			tail->next = ptr;
		}
		if (head == nullptr)
		{
			head = ptr;
		}
		tail = ptr;
		return ptr;
	}
	void pop_front()
	{
		if (head == nullptr)
		{
			return;
		}
		Node* ptr = head->next;
		if (ptr != nullptr)
		{
			ptr->prev = nullptr;
		}
		else
		{
			tail = nullptr;
		}
		delete head;
		head = ptr;
	}
	void pop_back()
	{
		if (tail == nullptr)
		{
			return;
		}
		Node* ptr = tail->prev;
		if (ptr != nullptr)
		{
			ptr->next = nullptr;
		}
		else
		{
			head = nullptr;
		}
		delete tail;
		tail = ptr;
	}
	Node* findIndex(int index)
	{
		this->index = index;
		Node* ptr = head;
		int n = 0;
		while (n != index)
		{
			if (ptr == nullptr)
			{
				return ptr;
			}
			ptr = next;
			n++;
		}

	}
};
int main()
{
	setlocale(LC_ALL, "Russian");

	List<string>list;
	cout << list.push_front("Соси писюн")->data << endl;
	cout << list.push_front("Я ебал твой рот")->data << endl;
	cout << list.push_back("Это задание я тоже в рот ебал")->data << endl;
	list.pop_front();
	list.pop_back();

	return 0;
}