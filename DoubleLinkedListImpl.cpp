//initializing a doubly-linked list node
#include<stdio.h>
#include<stdlib.h>

//Node constructor
struct Node {
    int data;
    struct Node* next;
    struct Node* prev; 

};

struct Node* head; // global variable -- pointer to the head node of the list

//Taking in a node and populate it with the constructor property on line 5
struct Node* getNeWNode(int x)
{
    //Creating a node in the heap portion of the memories
    struct Node* newNodePtr = (struct Node*)malloc(sizeof(struct Node));
    
    newNodePtr -> data = x;
    newNodePtr -> prev = NULL;
    newNodePtr -> next = NULL;

    return newNodePtr;

}  

//Function to add a node to the head of list:
void InsertAtHead(int x)
{
    struct Node* newNode = getNeWNode(x);
    //if the list is empty, the the values will be inserted into the head position of the linked list:
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;

}

//print function: 
void Print()
{
    struct Node* temp = head; 
    printf("Forward: ");
    while(temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }

    printf("\n");
}

//print in reverse
void ReversePrint(){
    struct Node* temp = head; 
    if(temp == NULL) return; //empty list, exit
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }

    //traversing backward using a prev pointer:
    printf("Reverse: ");
    while(temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> prev;
    }

    printf("\n");
    
}

//main function:
int main()
{
    // The list is empty intially
    head = NULL; //empty list
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(6); Print(); ReversePrint();
    InsertAtHead(8); Print(); ReversePrint();



    
}

