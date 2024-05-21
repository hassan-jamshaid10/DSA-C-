#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* prev;
};

class Doublyll
{
	node* head;
	node* tail;
public:
	Doublyll()
	{
		head = NULL;
		tail = NULL;
	}
	void insertathead(int d)
	{
		node* temp = new node;
		temp->data = d;
		temp->next = NULL;
		temp->prev = NULL;
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			head->prev = temp;
			temp->next = head;
			head = temp;
		}
	}
	void insertattail(int d)
	{
		node* temp = new node;
		temp->data = d;
		temp->next = NULL;
		temp->prev = NULL;
		if (tail == NULL)
		{
			tail = temp;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}
	void deletefromhead()
	{
		node* temp = new node;
		if (head == NULL)
		{
			cout << "Linked List is empty" << endl;
		}
		else if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
			return ;
		}
		else
		{
			temp = head;
			head = head->next;
			temp->prev = NULL;
			temp->next = NULL;
			delete temp;
			return ;
		}
	}
	void deletefromtail()
	{
		if (tail == NULL && head ==NULL)
		{
			cout << "Linked List is empty" << endl;
		}
		else if (head == tail)
		{
			delete tail;
			head = NULL;
			tail = NULL;
			return ;
		}
		else
		{
			node* temp = tail;
			if(tail->prev ==NULL)
			{
				tail = NULL;
			}
			else
			{
				tail = tail->prev;
				tail->next = NULL;
			}
			delete temp;
		}
	}
	void displayfromhead()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "<->";
			temp = temp->next;
		}
		cout << "NULL <->";
		cout << endl;
	}
	void displayfromtail()
	{
		node* temp = tail;
		while (temp != NULL)
		{
			cout << temp->data << "<->";
			temp = temp->prev;
		}
		cout << "NULL <->";
		cout << endl;
	}
};

int main()
{
	Doublyll l;
	l.insertattail(5);
    l.insertattail(6);
	l.insertattail(7);
	l.deletefromtail();

	l.displayfromtail();
}