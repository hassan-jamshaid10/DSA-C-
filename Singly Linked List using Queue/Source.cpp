#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class Queue
{
	node* front;
	node* rear;
public:

	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	bool isempty()
	{
		if (front == NULL)
		{
			return true;
		}
		return false;
	}
	void enqueue(int d)
	{
		node* temp = new node;
		temp->data = d;
		temp->next = NULL;
		if (front == NULL && rear == NULL)
		{
			front = temp;
			rear = temp;
		}
		else
		{
			node* t = front;
			while (t->next != NULL)
			{
				t = t->next;
			}
			t->next = temp;
		}
	}
	int dequeue()
	{
		if (isempty())
		{
			cout << "Queue is empty" << endl;
			return 0;
		}

		else
		{
			node* temp = front;
			front = front->next;
			temp->next = NULL;
			delete temp;
		}

	}
	void traverse()
	{
		node* temp = front;
		while (temp != NULL)
		{
			cout << temp->data << " ->";
			temp = temp->next;

		}
		cout << "NULL->";
		cout << endl;
	}

};

int main()
{
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	cout << "Queue:" << endl;
	q.traverse();
	cout << endl;
	cout << "Queue after dequeue:" << endl;
	q.dequeue();
	q.traverse();

}