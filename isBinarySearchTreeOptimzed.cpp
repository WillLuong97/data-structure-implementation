//C++ program to check of a binary tree is a BST:
//Time complexity: O(n) more efficient

//Node constructor: 
struct Node
{
    int data; 
    Node *left; 
    Node *right;
}


//check if binary search tree using upper and lower bound
//time c 
bool IsBSTUtils(Node* root, int minVal, int maxVal)
{
    //base case: the tree is empty:
    if (root == NULL)
    {
        return true;
    }
    //return true if BST, false otherwise. 
    if(root -> data > minVal && root -> data < maxVal && IsBinarySearchTree(root -> right, root -> data, maxVal) && IsBinarySearchTree(root -> left, minVal, root -> data))
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool IsBinarySearchTree(Node* root)
{
    return IsBSTUtils(root, INT_MAX, INT_MIN);
}