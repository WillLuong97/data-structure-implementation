//C++ program to check of a binary tree is a BST:
//Time complexity: O(n^2)

//Node constructor: 
struct Node
{
    int data; 
    Node *left;
    Node *right;
}

//Method 1: 

//Return true if all the value in the subtree is lesser than the value
bool IsSubTreeLesser(Node* root, int value)
{
    //base case: tree is empty:
    if (root = NULL)
    {
        return true;
    }

    if(root -> data < value && IsSubTreeLesser(root -> left, value) && IsSubTreeLesser(root -> right, value))
    {
        return true;
    }

    else
    {
        return false;
    }
}//end of IsSubTreeLeseer()

//Return true if all the value in the subtree is greater than the value
bool IsSubTreeGreater(Node* root, int value)
{
    //base case: tree is empty:
    if (root = NULL)
    {
        return true;
    }

    if(root -> data > value && IsSubTreeLesser(root -> left, value) && IsSubTreeLesser(root -> right, value))
    {
        return true;
    }

    else
    {
        return false;
    }

} //end of IsSubTreeGreater()

bool IsBinarySearchTree(Node* root)
{
    //base case: the tree is empty:
    if (root == NULL)
    {
        return true;
    }
    //return true if BST, false otherwise. 
    if(IsSubTreeLesser(root -> left, root -> data) && IsSubTreeGreater(root -> right, root -> data) && IsBinarySearchTree(root -> left) && IsBinarySearchTree(root -> right))
    {
        return true;
    }

    else
    {
        return false;
    }
}