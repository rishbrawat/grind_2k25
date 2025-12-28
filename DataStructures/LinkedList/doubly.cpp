#include<iostream>
using namespace std;

/*
doubly linked list
___________________
in doubly linked list, each node is connected to its previous and next node except the first and last node.

the head node or first node in the list does not point to other node, but points at nullptr.
similiarly the tail node points next to the nullptr.


key members:
   data: the actual data that the node holds
   prev: previous node reference
   next: next node reference

*/

struct Node {
   int data;
   struct Node* next;
   struct Node* prev;
};

// print the list
void printList(struct Node* temp) {
   struct Node* ptr =  temp;
   while(ptr!=nullptr) {
      cout << ptr->data << ' ';
      ptr = ptr->next;
   }
   cout << endl;
}

int main() {
   struct Node* head = new Node;
   head->data = 10;
   head->prev = nullptr;
   
   struct Node* item2 = new Node;
   item2->data = 20;
   item2->next = nullptr;

   // update location references
   item2->prev = head;
   head->next = item2;


   printList(head);
   
   // free the mem
   delete head;
   delete item2;

   return 0;
}