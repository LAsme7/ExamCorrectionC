#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "list.c"
Node* head;
Node* initializeList()
{
    Node* head = createNode(1);
    Node* current = head;

    for (int i = 2; i <= 5; i++)
    {
        Node* newNode = createNode(i);
        setNext(current, newNode);
        current = newNode;
    }

    return head;
}
void printList(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        printf("%d -> ", getValue(current));
        current = getNext(current);
    }
    printf("NULL\n");
}

void insertAtPosition(int value, int pos){
 Node* new_Node = createNode(value);
 ///If list is empty :
 if (head == NULL){
    head = new_Node;
    return;
 }
 ///If  position if out of bounds :
 if (pos < 0 ){
    printf("Invalid position\n");
    return;
 }
 ///At beginning :
 if (pos == 0){
    setNext(new_Node,head);
    head = new_Node;
    return;
 }
 ///At middle and end :
 Node* current = head;
 for(int i =0; i< pos-2; i++){
    current= getNext(current);
 }
 if (current==NULL){
    printf("Invalid position\n");
    return;
 }
 setNext(new_Node,getNext(current));
 setNext(current,new_Node);


}
int main()
{
    head = NULL;
    insertAtPosition(5,0);
    insertAtPosition(6,1);
    insertAtPosition(7,0);
    insertAtPosition(9,4);

    printList(head);

    return 0;
}
