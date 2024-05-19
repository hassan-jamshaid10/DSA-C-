#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class stack
{
	node* top;
public:
	stack()
	{
		top = NULL;
	}
	bool isempty()
	{
		if (top == NULL)
		{
			return true;
		}
		return false;
	}
	
	void push(int d)
	{
		node* temp = new node;
		
		if (!temp)
		{
			exit(1);
		}
		temp->data = d;
		temp->next = top;
		top =temp;
	}
	int pop()
	{
		node* temp = new node;
		if (isempty())
		{
			exit(1);
		}
		temp = top;
		top = top->next;
		delete temp;

	}
	int peak()
	{
		return top->data;
	}
	void display()
	{
		node* temp = top;
		while (temp != NULL)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
	}
};

int main()
{
	stack s;
	s.push(5);
	s.push(8);
	s.display();
}