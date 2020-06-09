//C++ program to demonstrate linked list implementation of the Queue
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std; 

//Node constructor: 
struct Node{
    int data; 
    struct Node* next; 
}; 


//Queue constructor:
struct Queue{
    struct Node *front; 
    struct Node *rear; 


    void Enqueue(int x)
    {
        struct Node* temp = new Node;
        temp -> data = x; 
        temp -> next = NULL;

        //if the list is empty:
        if (front == NULL && rear == NULL)
        {
            //since the list is empty, with the new values being enqueued, both the Front and rear will point to that value. 
            front = rear = temp; 
            return;
        }

        rear -> next = temp;
        //the address of temp is now being stored in the rear. 
        rear = temp;
    }

    void Dequeue()
    {
        //dequeue would only handle the front, since a queue is First In First Out: 
        struct Node* temp = front; 
        //if the list is currently empty:
        if (front == NULL)
        {
            return; //nothing to remove
        }
        //if the queue is full:
        if(front == rear)
        {
            front = rear = NULL;
        }

        else{
            front = front -> next; 
        }
        
        free(temp);
    }

    


};
//function to print out the queue structor

int main()
{
    //Creatint a queue: 
    Queue q; 
    q.Enqueue(10);
    q.Enqueue(2);
    q.Enqueue(4);
    q.Enqueue(16);
    q.Enqueue(12); 
    q.Dequeue(); 
    

}