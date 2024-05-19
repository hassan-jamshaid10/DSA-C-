#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

class linkedlist
{
	node* head;
	node* tail;
public:
	linkedlist()
	{
		head = NULL;
		tail = NULL;
	}
	void inseert(int d)
	{
		node* temp = new node;
		temp->data = d;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			node* t = head;
			while (t->next != NULL)
			{
				t = t->next;
			}
			t->next = temp;
		}
		return;
	}
	node* arr(int arr[], int s)
	{
		for (int i = 0; i < s; i++)
		{
			inseert(arr[i]);
		}
		return head;
	}
	node* arrrev(int arr[], int s,int k)
	{
		cout << endl;
		for (int i = k-1 ; i >= 0; i--)
		{
			cout << arr[i]<<"->";
		}
		for (int i = s-1 ; i >= k; i--)
		{
			cout << arr[i] << "->";
		}
		return head;
	}
	void display()
	{
		while (head != NULL)
		{
			cout << head->data << "->";
			head = head->next;
		}
	}
	bool comapre(linkedlist l)
	{
		node* current = head;
		node* c2 = l.head;
		while (current && c2)
		{
			if (current->data != c2->data)
			{
				return false;
			}
			current = current->next;
			c2 = c2->next;
		}
		if (current || c2)
		{
			return false;
		}
		return true;
	}
	node* removeduplicate()
	{
		node* c = head;
			while (c->next != NULL)
			{
				 c->data+=c->next->data;

				 c=c->next;

			}
			node* temp = new node;
			temp->data= c->data;
			return temp;
	}
};

int main()
{
	linkedlist l,l2;

	//int arr[] = { 1,2,3,4,5 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//l.arr(arr, n);
	//l.display();
	////l.arrrev(arr, n, 3);
	//cout << endl;
	//int arr2[] = { 1,2,3,4,5 };
	//int n2 = sizeof(arr2) / sizeof(arr2[0]);
	//l2.arr(arr2, n2);
	l.inseert(6);
	l2.inseert(5);
	l2.inseert(5);
	l2.inseert(7);
     cout<<l2.removeduplicate();
	//l2.inseert(x);

	cout<<"Equal or not:"<<l.comapre(l2);
}