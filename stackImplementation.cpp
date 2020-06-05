//Stack - Array based implementation. 
#include<stdio.h>
#define MAX_SIZE 101
//initializing the array size.
int A[MAX_SIZE];
int top = -1; //top is empty
void push(int x)
{
    //overflow error: 
    if(top == MAX_SIZE - 1)
    {
        printf("Error! Stack overflow!");
        return; 
    }

    top++;
    A[top] = x;
}

void pop()
{
    //if the stack is empty, there would be no pop()
    if(top == -1)
    {
        printf("Error! No element left to pop");
        return; // break
    }
    top--; 
}

int Top()
{
    return A[top];
}

void Print()
{
    int i; 
    printf("Stack: ");
    //looping through the stacks
    for(i = 0; i <= top; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");
}

int main()
{
    push(2); Print();
    push(4); Print();
    push(5); Print();
    push(6); Print();
    pop(); Print();
    push(12); Print();

} //end of program

