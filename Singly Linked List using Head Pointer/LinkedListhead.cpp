// LINKED LIST USING HEAD deletion and insertion
#include<iostream>
using namespace std;


class Node
{
public:
 int data;
 Node* next;
};
class linkedlist
{
 Node* head;
public:


 linkedlist()
 {
  head = NULL;
 }
 void insertathead(int d)
 {
  Node* temp = new Node;
  temp->data = d;
  temp->next = NULL;
  if (head == NULL)
  {
   head = temp;
  }
  else
  {
   temp->next = head;
   head = temp;
  }
 }
 void insertattail(int d)
 {
  Node* temp = new Node;
  temp->data = d;
  temp->next = NULL;
  if (head == NULL)
  {
   head = temp;
  }
  else
  {
   Node* t = head;
   t->next = temp;
   t = temp;
  }
 }
 void deletefromhead()
 {
  if (head == NULL)
  {
   cout << "Linked list is empty" << endl;
  }
  else
  {
   Node* temp = head;
   head = head->next;
   temp->next = NULL;
   delete temp;
  }
 }
 void deletefromtail()
 {
	
  if (head == NULL)
  {
   cout << "Linked list is empty" << endl;
  }
  else
  {
   Node* temp = head;
    while (temp->next->next != NULL)
    {
     temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
  }
 }
 void display()
 {
  Node* temp = head;
  while (temp != NULL)
  {
   cout << temp->data << "->";
   temp = temp->next;
  }
  cout << endl;
 }
};


int main()
{
 linkedlist l;
 l.insertathead(5);
 l.insertathead(6);
 //l.insertattail(4);
 //l.insertattail(8);
 l.display();
 l.deletefromhead();
 l.deletefromtail();
 cout << endl;
 l.display();
}