/* A C++ program to implement and demostrate the Inorder successor in a Binary Search Tree*/
#include<iostream>
using namespace std; 

//Node constructor: 
struct Node{
    int data, 
    struct Node *left;
    struct Node *right; 
};

//Function to find the Minimum node in a tree:
struct Node* FindMin(struct Node* root, int data)
{
    // if the tree is empty, there is no minimum
    if (root == NULL)
    {
        return; 
    }
    //if the tree has element in it:
    while(root != NULL)
    {
        //in any BST structure, the smaller element would always be in the left
        //therefore, the smallest element would be the leftmost node in a tree.
        root = root -> left;
    }

    return root;
}//end of FindMin()
//Function to find the successor:
struct Node* Getsuccessor(struct Node* root, int data)
{
    //search for the node in the tree - O(h); h is the height of the tree
    struct Node* current = Find(root, data);
    //if the current node is not the in the tree:
    if(current == NULL)
    {
        return NULL;
    }
    //Case 1: Node has a right subtree
    if(current -> right != NULL)
    {
        return FindMin(root -> right, data);
    }

    //Case 2: Node has no right subtree - O(h) ; h is the heiht of a tree
    else {
        //declare a pointer to the current node
        struct Node* successor = NULL;
        struct Node* ancestor = root; 
        while(ancestor != current)
        {
            if(current -> data < ancestor -> data)
            {
                successor = ancestor;
                //Keep iterating through the tree:
                ancestor = ancestor -> left;

            }

            else
            {
                ancestor = ancestor -> right;
            }

            
        }
        return ancestor;
    }
}//end of function Getsuccessor()