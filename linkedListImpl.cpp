//Linked List implementation: Inserting a Node at beginning
#include<stdlib.h>
#include<stdio.h>

//structure of the linked list
struct Node
{
    int data; 
    Node* next; //address of the next Node!
    
};

Node* head; //Global Function
//function definition:
//Inserting a node into the head node:
// void Insert(int data, int n)  
// {
    
//     Node* temp = (Node*)malloc(sizeof(struct Node));    
//     temp -> data = x;      //the value of x being stored.   
//     temp -> next = head; //memory location of the next values in the list.
//     head = temp;

// }

//Inserting into the list at a particular node:
void Insert(int data, int n)
{
    //temp1 will hold the value and address of the values that are needed to be hold.
    Node* temp1 = new Node(); //an entire new node to be added into the list
    temp1 -> data = data;
    temp1 -> next = NULL;

    //inserting into the head node:
    if(n == 1)
    {
        temp1 -> next = head; // the pointer would point to the head position
        head = temp1;
        return;
    }

    Node* temp2 = head;
    //traversing the list to the previous nodes of the location that we want to insert values into
    for(int i = 0; i < n-2; i++)
    {
        //The loop will stop at n-2 and the temp2 pointer would point to the address of n -1 p
        temp2 = temp2 -> next;

    }
    //the link of temp1 would now point to n
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
}

void Print()
{
    Node* temp = head;
    // traversing the linked list:
    printf("List is: ");
    while (temp != NULL)        
    {
        printf(" %d", temp -> data);       
        temp = temp -> next;
    }
    printf("\n");

}

void Delete(int n)// Delete node at poiston n:
{
    //initializing a head node:
    struct Node* temp = head;
    
    //if the heads need to be removed:
    if (n == 0)
    {
        head = temp -> next; //Head would be changed!
        free(temp); //Free up the memory of deleted values
        return;
    }

    // if the postion is more than the nodes in the list:
    if(temp == NULL || temp -> next == NULL)
    {
        return;
    }

    //Find the previous node of the node that we need to remove:
    //Also means traversing the list to get to the nodes needs to be deleted
    for (int i = 0; temp!=NULL && i<n-1; i++)
    {
        temp = temp -> next;
    }

    //Node temp -> next is the node to be deleted
    // Store pointer to the next of node to be deleted 
    struct Node* next = temp -> next -> next;

    //unlink the node from linked list
    free(temp->next);   //free memory of the deleted values. 

    temp->next = next;  //Unlike the deleted node from the list, skipping the deleted link and point them to the next values.
     
}


//main function:
int main(){
    head = NULL; //The list is currently empty
    printf("How many numbers are in the list?\n");
    int n, i, num, position;
    //user input:
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        //Asking the user for the position of the node to be deleted:
        printf("Enter the value to be insert into the list: ");
        scanf("%d", &num);
        printf("Enter a position to insert the value into: ");
        scanf("%d", &position);
        Insert(num, position);
        Print();
    }

    //Asking the user for the position of the node to be deleted:
    printf("Enter a position to be deleted:  \n");
    scanf("%d", &n);
    Delete(n); 
    Print();

}


