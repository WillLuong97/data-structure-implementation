//Linked list implementation of Stack
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 101
//intializing the array: 
int A[MAX_SIZE];


//a node constructor
struct Node
{
    int data; 
    struct Node* link; 
};

//Global variable: we will assume the array is empty at the beginning
struct Node* top = NULL;

void Push(int x)
{
    struct Node* temp = new Node();
    //temp will contains the data values of x
    temp -> data = x; 
    // temp address would be pointing the head of the stack
    temp -> link  = top; 
    //top will now contain the data values of temp, which is x
    top = temp; 

} 

void Pop()
{
    //creating a local temp values:
    struct Node* temp; 
    
    if (top == NULL)
    {
        printf("Error! There are no more values to pop");
        return; //break
    }
    
    //temp will take the value at the top of the stacks
    temp = top; 
    // top will now point to the next values in the stacks.
    top = top -> link; 
    // the values at the top of the stacks will now be destroyed
    free(temp);
}



void Print()
{
    Node* temp = top;
    // traversing the linked list:
    printf("List is: ");
    while (temp != NULL)        
    {
        printf(" %d", temp -> data);       
        temp = temp -> link;
    }
    printf("\n");

}

int main()
{
    Push(2); Print();
    Push(4); Print();
    Push(3); Print();
    Push(5); Print();
    Push(8); Print();
    Pop(); Print();
}

