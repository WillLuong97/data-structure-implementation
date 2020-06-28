/* C++ program to delete a node from Binary Search Tree:
*/ 
#include<iostream>
using namespace std; 

//Node constructor:
struct Node{
    int data; 
    struct Node *left;
    struct Node *right;
};

//function to delete the node
struct Node* Delete(struct Node *root, int data)
{
    //base case: tree is empty: 
    if(root == NULL)
    {
        return root;
    }

    //if the data is less than the root node, then it should be on the left sub-tree:
    else if(data < root -> data)
    {
        //at every iteration, we will update the address of the current node pointer
        root -> left =  Delete(root -> left, data);

    }

    //if the data is greater than the root node, we will find the target node in the right sub-tree
    else if(data > root -> data)
    {
        //at every iteration, we will update the address of the current node pointer
        root -> right = Delete(root -> right, data);
    }

    else
    {
        //found the target readey to delete it 
        //case 1: no child/ leaf node
        if(root -> left == NULL && root -> right == NULL)
        {
            delete root;
            root = NULL;
           
        }

        //Case 2: One child: 
        else if(root -> left == NULL)
        {
            struct Node *temp = root; 
            root = root -> right;
            delete temp;
           
        }

        else if(root -> right == NULL)
        {
            //creating a temp node that would take the value of the current root to be deleted
            struct Node *temp = root;
            //the new replaced root will be in the left child
            root = root -> left;
            delete temp; //delete the target node
            
        }

        /*case 3: 2 children: 
            Solution 1: Find min in the right subtree, copy value in targeted node, delete duplicate from right one
            Solution 2: Find max in the left subtree, copy in targeted node, delete duplicate from the right one. 
        */

        else {
            struct Node* temp = FindMin(root -> right);
            root -> data = temp -> data; 
            root -> right = Delete(root -> right, temp -> data);
        }
    }

    return root; //return the new memory address of the new root.
}