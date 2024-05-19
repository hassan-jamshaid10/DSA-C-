// LINKED LIST USING HEAD AND TAIL
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
 Node* tail;
public:


 linkedlist()
 {
  head = NULL;
  tail = NULL;
 }
 void insertathead(int d)
 {
  Node* temp = new Node;
  temp->data = d;
  temp->next = NULL;
  if (head == NULL && tail == NULL)
  {
   head = temp;
   tail = temp;
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
  if (head == NULL && tail == NULL)
  {
   head = temp;
   tail = temp;
  }
  else
  {
   tail->next = temp;
   tail = temp;
  }
 }
 void deletefromhead()
 {
  if (head == NULL && tail == NULL)
  {
   cout << "Linked List is empty" << endl;
  }
  else if (head == tail)
  {
   delete tail;
   head = NULL;
   tail = NULL;
   return;
  }
  else
  {
   Node* temp = head;
   head = head->next;
   temp->next = NULL;
   //cout << "Value to be deleted:"<< temp->data << endl;
   delete temp;
  }
 }


 void deletefromtail()
 {
  if (head == NULL && tail == NULL)
  {
   cout << "Linked List is empty" << endl;
  }
  else if (head == tail)
  {
   delete tail;
   head = NULL;
   tail = NULL;
   return;
  }
  else
  {
   Node* temp = head;
   if (temp != tail)
   {
    Node* current = temp;
    while (current->next != tail)
    {
     current = current->next;
    }
    tail = current;
    tail->next = NULL;
    return;
   }
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
 l.insertattail(4);
 l.insertattail(8);
 l.display();
 l.deletefromhead();
 l.deletefromtail();
 cout << endl;
 l.display();
}