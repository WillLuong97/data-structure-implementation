//string reversal using stack
#include<iostream>
#include<stack>  //stack template library in C++
using namespace std; 


//constructor to create a Node
struct Node{
    int data; 
    struct Node* next;
}
//global variables to hold the head values: 
struct Node* head; 
//constructor to create a stack: 
// class Stack{ 
//     private: 
//         char A[10];
//         int top; 
//     public: 
//         void push(int x); 
//         void pop(); 
//         void Top(); 
//         void isEmplty();
// }
void Reverse(char *C, int n)
{
    stack<char> S; //stack of character
    for(int i = 0; i<n; i++)
    {
        S.push(C[i]); //pushing each characters from the character into list onto the stacks

    }

    //loop for pop
    for(int i = 0; i < n; i++)
    {
        C[i] = S.top(); //build-in function to overwrite the chacracter at index i; 
        S.pop(); //perfomr pop;
    }
    
}

//Reverse a linked list using stack 
void ReverseLinkedList()
{
    //if the list is empty, return nothing
    if(head == NULL)
    {
        printf("The list is empty!");
        return; 
    }; 
    stack<struct Node*> S; //creating a stack that contains the a linked list structure. 
    //traversing through the linked list: 
    Node* temp = head; 
    //adding each node into the array
    while(temp != NULL)
    {
        S.push(temp);
        temp = temp -> next; 
    }

    head = temp; 
    temp = S.top();
    S.pop();
    //loop for pop
    while (!S.isEmpty())
    {
       temp -> next = S.top();
       S.pop();
       temp = temp -> next;
    }

    temp -> next = NULL;
}

int main()
{
    char C[51];
    printf("Enter a string: ");
    gets(C); 
    Reverse(C, strlen(C));
    printf("Output = %s ", C);

}



