#include <iostream>
#include<string>
using namespace std;

template<typename T>
class Dick
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
			this->prev = this->next = NULL;
		}
	};
	Node* head;
	Node* tail;
	Node size;
public:
	Dick()
	{
		this->head = this->tail = NULL;
	}
	Node* push_front(T data) 
	{
		Node* ptr = new Node(data);

		ptr->next = head;
		if (head != NULL)
			head->prev = ptr;
		if (tail == NULL)
			tail = ptr;
		head = ptr;

		return ptr;
	}


	Node* push_back(T data) 
	{
		Node* ptr = new Node(data);

		ptr->prev = tail;
		if (tail != NULL)
			tail->next = ptr;
		if (head == NULL)
			head = ptr;
		tail = ptr;

		return ptr;
	}
	int* pop_front()
	{
		if (head == NULL) return nullptr;

		Node* ptr = head->next;
		if (ptr != NULL)
			ptr->prev = NULL;
		else
			tail = NULL;

		delete head;
		head = ptr;
	}


	Node* pop_back()
	{
		if (tail == NULL)
		{ 
			return NULL;
		}
			

		Node* ptr = tail->prev;
		if (ptr != NULL)
			ptr->next = NULL;
		else
			head = NULL;

		delete tail;
		tail = ptr;
	}
	Node* find(T size)
	{
		Node* ptr = head;
		int n = 0;
		while (n != size)
		{
			if (ptr == NULL)
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
	Dick<string>list;
	list.push_front("Соси писюн");
	list.push_front("Я ебал твой рот");
	list.push_back("Это задание я тоже в рот ебал");
	list.pop_front();
	list.pop_back();

	return 0;
}