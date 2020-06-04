//Linked List implementation: Inserting a Node at beginning
#include<stdlib.h>
#include<stdio.h>

//structure of the node:
struct Node
{
    int data;
    Node* next; 
}; 

//Global variables for head:
struct Node* head;

struct Node* Insert(struct Node* head, int data)
{
    Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    if(head == NULL) head = temp;
    else
    {
        Node* temp1 =  head;
        while(temp1-> next != NULL) temp1 = temp1 -> next;
        temp1 -> next = temp; 
    }

    return head;

}

void Print(Node* head) {
    while(head != NULL)
    {
        printf("%d\n", head -> data);
        head = head -> next;
    }
}

void reversePrint(struct Node* p)
{
    if(p == NULL)
    {
        return; //the list is exhausted
    }
    reversePrint(p->next);
    printf("%d", p->data);
}

//Print linked list using recursion:
void PrintWithRecursion(struct Node* p)
{
    if(p == NULL) return; //Exit condition as the preojec
    printf("%d", p->data);      //First print the value in the Node
    PrintWithRecursion(p->next); //Recursive call
}


//Iternative method: traverse the list and at each iteration, the linked will point to the previous ones
struct Node* Reverse(struct Node* head)
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;

    //traversing through the list:
    while(current != NULL)
    {
        next = current -> next;
        current -> next = prev; //The link of the current node would now be potining to the previous node. 
        prev = current; //the data value of previous would now be current
        current = next; 
    }
    head = prev; 
    return head;
}

//RECURSION METHOD: reverse a linked list by using recursive function
struct Node* ReverseWithRecursion(struct Node* p)
{
    if (p == NULL)
    {
        return NULL;
    }

    //exit condition:
    if(p -> next == NULL)
    {
        // head = p;
        return p;
    }

    Node* q = ReverseWithRecursion(p -> next);
    q-> next = p;
    p->next = NULL;

    return p;
}


int main() 
{
    struct Node* head = NULL; //local variables of head 
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);
    Print(head);
    // reversePrint(head);

    head = ReverseWithRecursion(head);
    Print(head);
    // PrintWithRecursion(head);
    // Print(head);
}