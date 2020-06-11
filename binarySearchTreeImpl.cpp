 /* Binary Search Tree (BST): a tree in which for each node
 the value of all the nodes in the left subtree is lesser or equal and
 value of all the nodes in the right subtree is greater. 

 ---Computer Implementation method: using pointer or references, a node can be defined as an object 
 with 3 fields, the data value. left child and right child.

 ---Nodes will be created in heap using malloc function in 'C' or new operatir in C++
 */

#include<iostream>
#include<stdlib.h>
using namespace std;
#define COUNT 10
//a Node constructor: store only interger data points.
struct BstNode{
    int data;
    struct BstNode *left;
    struct BstNode *right; 
};

//function to create a node based on the data
//the node created will be in the heap memmory of the program
//Return: the address of the node.
BstNode* GetNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}//end of GetNewNode()


//inserting a node into the tree
BstNode* Insert(BstNode* root, int data)
{
    //if the tree is empty, the value will be inserted into the root node
    //To do so: the root will  point to the data node pointer
    if (root == NULL){
        root = GetNewNode(data);
    }
    //if the tree is not empty, we will check two cases:
    else if(data <= root -> data)
    {
        //make a recursive call to add data into the left child node. 
        root -> left = Insert(root -> left, data);
    }

    else{
        root -> right = Insert(root -> right, data);
    }
    return root;
} //end of Insert()

//checking if the data is in the tree or not
bool Search(BstNode* root, int data)
{
    //if the tree is currently empty, which means the data is not in there:
    if(root == NULL){
        return false;
    }
    //if the data is in the root node
    else if (root -> data == data)
    {
        return true;
    }

    //if the data is not in the root node and is greater
    else if(data >= root->data)
    {
        //search for the data in the right subtree area
        return Search(root -> right, data);
    }

    // if the data is not in the root node and is lesser:
    else 
    {
        //search for the data in the left subtree area
        return Search(root -> left, data);
    }

}//end of Search()

//function to find the minimum node in the tree: 
int Min(BstNode* root)
{
    //if the list is empty, then there is no minimum node:
    if (root == NULL)
    {
        cout << "Error! Tree is empty!";
        return -1; 
    }

    // keep walking down the tree during the left side of the tree, as the left most element of the tree is the minumum value
    else if(root -> left == NULL)
    {
        return root -> data;
        
    }

    //calling the function recursively until the minimum is found:
    return Min(root -> left);
   
}// end of Min()


//function to find the maximum values in the right side of the tree, as the right most element of the tree is maximum values:
int Max(BstNode* root)
{
    //if the list is empty, there is no maximum to find: 
    if(root == NULL)
    {
        cout << "Error! Tree is empty!";
        return -1; 
    }

    //keep walking down the tree during the right side of the tree, as the rightmost element in the tree is the maximum values
    else if(root -> right == NULL)
    {
        return root -> data;
    }

    //calling function recursively until the maximum value is found
    return Max(root -> right);
}
// Function to print binary tree in 2D  
// It does reverse inorder traversal  
void print2DUtil(BstNode *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    print2DUtil(root->right, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->data<<"\n";  
  
    // Process left child  
    print2DUtil(root->left, space);  
}  
  
// Wrapper over print2DUtil()  
void print2D(BstNode *root)  
{  
    // Pass initial space count as 0  
    print2DUtil(root, 0);  
}  


//main function to excute the program 
int main()
{
    BstNode* root = NULL;  // pointer to root node //setting the tree to be empty and the root pointer would be NULL
     
    //update the address of the root in the tree after each insertion
    root = Insert(root, 15);
    root = Insert(root, 23);
    root = Insert(root, 12);
    root = Insert(root, 34);
    root = Insert(root, 8);
    root = Insert(root, 25);

    print2D(root);

    // //Testing find min:
    cout << Min(root) << endl;

    // //Testing find max: 
    cout << Max(root) << endl;

    //Testing for search function:
    int number;
    cout << "Please enter a number to test: ";
    cin >> number;
    if(Search(root, number) == true)
    {
        cout << "Found!\n";
    }

    else
    {
        cout << "Not Found!\n";
    }
} //end of function