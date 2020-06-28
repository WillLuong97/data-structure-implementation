// this C++ program will show how to find the min and max node in a tree using a loop: 

#include<iostream>
#include<stdlib.h>
using namespace std; 
#define COUNT 10

//Binary search tree constructor: store integer values:
struct BstNode{
    int data; 
    BstNode* left; 
    BstNode* right; 
};

//extracting the node address
BstNode* getNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode -> data = data; 
    newNode -> left = newNode -> right = NULL;
    return newNode;
}//end of getNewNode()

BstNode* Insert(BstNode* root, int data)
{
    //if the function is empty, the data will be added to the root:
    if(root == NULL)
    {
        root = getNewNode(data);
    }

    //if the list is currently having elements in it:
    while(root != NULL)
    {
        if(data >= root -> data)
        {
            root -> right = getNewNode(data);
        }

        else
        {
            root -> left = getNewNode(data);
        }
        
    }

    return root;

}//end of Insert()

int findMin(BstNode* root)
{
    int min = 0;

    //if the list is empty, there is nothing to search for:
    if (root == NULL)
    {
        cout << "Tree is empty!";
        return -1; 
    }

    // keep walking down the tree during the left side of the tree, as the left most element of the tree is the minumum value
    while(root != NULL)
    {
        if(root -> left == NULL)
        {
            min = root -> data;
        }

    }
    return min;
  
}// end of function findMin()


int findMax(BstNode* root)
{
    int max = 0;
    //if the list is empty, there is nothing to look for:
    if(root == NULL)
    {
        cout << "Tree is empty!";
        return -1; 
    }

    while(root != NULL)
    {
        if(root -> right == NULL)
        {
            max =  root -> data;
        }
    }
    return max;
}


// bool Search(BstNode* root, int data)
// {
//     //if the tree is empty, then there is notthing to look for
//     if (root == NULL)
//     {
//         cout << "Error! Tree is empty";
//         return false; 
//     }

//     if (data = root -> data)
//     {
//         //the data is in the root node:
//         return true;
//     }

//     while(root != NULL)
//     {
//         if(data >= root -> data)
//         {
//             while(root -> right != NULL)
//             {

//             }

//         }

//     }

// }

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

//Main function to run the components:
int main()
{
    //creating a root node for the tree:
    BstNode* root = NULL; //the tree is empty at the beginning
    
    //at every insertion, the local root node is updated with a new address. 
    root = Insert(root, 15);
    root = Insert(root, 23);
    root = Insert(root, 12);
    root = Insert(root, 34);
    root = Insert(root, 8);
    root = Insert(root, 25);

    //printing out the binary search tree 
    print2D(root);

    //Testing find min:
    cout << "The minimum value in the tree is: " << findMin(root) << endl;
    // //Testing find max: 
    // cout << "The minimum value in the tree is: " << findMax(root) << endl;
    

    //Testing for search function:
    int number;
    cout << "Please enter a number to test: ";
    cin >> number;
    // if(Search(root, number) == true)
    // {
    //     cout << "Found!\n";
    // }

    // else
    // {
    //     cout << "Not Found!\n";
    // }


}//end of program.
