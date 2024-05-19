#include<iostream>
using namespace std;


struct Node
{
 int data;
 Node* next;
};


class linkedl
{
 Node* tail;


public:


 linkedl()
 {
  tail = NULL;
 }
 void insertathead(int d)
 {
  Node* temp = new Node;
  temp->data = d;
  temp->next = NULL;
  if (tail == NULL)
  {
   tail = temp;
   tail->next = temp;
  }
  else
  {
   temp -> next = tail->next;
   tail->next = temp;
  }
 }
 void insertattail(int d)
 {
  Node* temp = new Node;
  temp->data = d;
  temp->next = NULL;
  if (tail == NULL)
  {
   tail = temp;
   tail->next = temp;
  }
  else
  {
   temp->next = tail->next; //temp pointer will point tail next
   tail->next = temp; //temp pointer will go in tail next
   tail= temp; // value of temp goes in tail
  }
 }
 void insertatposition(int d, int pos)
 {
  if (pos < 0)
  {
   return;
  }
  Node* temp = new Node;
  temp->data = d;
  temp->next = NULL;
  if (pos == 0) //at begining of Linkedlist
  {
   tail = temp;
       return;
  }
  Node* current = tail;


  for (int i = 0; i < pos - 1 && current != NULL;i++)// to check the insertion point and position before insertion
  {
   current = current->next;
  }


  if (current == NULL)// if the position is beyond the end
  {
   delete temp;
   return;
  }
  //insert at specific position
  temp->next = current->next;
  current->next = temp;
  
  if(temp->next==NULL)
  {
      tail=temp;
  }
 }
 void display()
 {
  if (tail == nullptr)
   cout << "LL is empty" << endl;
  else
  {
   Node* temp = tail->next;
   while (1)
   {
    cout << temp->data << "->";
    temp = temp->next;
    if (temp == tail->next)
     break;
   }
   cout << endl;
  }
 }
};




int main()
{
 cout << "Inserting at Head using tail Pointer" << endl;
 linkedl l1;
 l1.insertathead(12);//3
 l1.insertathead(13);//2
 l1.insertathead(16);//1
 l1.insertathead(15);//0
 l1.display();
 l1.insertatposition(14, 2);
 l1.display();
 cout << "Inserting at tail using tail Pointer" << endl;
 linkedl l;
 l.insertattail(4);
 l.insertattail(5);
 l.display();


}