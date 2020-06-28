/* Depth First Search Traversal 
    - Preorder: <root><left><right>
    - Inorder: <left><root><right>
    - Postorder: <left><right><root>
*/

#include<stdlib.h>
#include<iostream>
using namespace std;

//Node constructor: 
struct Node {
    char data; 
    Node *left;
    Node *right;
}

/* Preorder: 
    1. Visit root
    2. Vist left subtree
    3. Visit right subtree

    ==> Time complexity: O(n); n in the number of node.
    ==> Space complexity: O(h); h is the height of the tree. 
            Worst: O(n) 
            Best/Average: O(logn)

*/
void Preorder(struct Node *root)
{
    //if the tree is empty, then there is nothing to work on:
    if(root == NULL)
    {
        return;
    }
    printf("%c ", root -> data);
    //calling function recursively until the left and right node are selected:
    Preorder(root -> left);
    Preorder(root -> right);

}

/* Inorder:
    1. Visit left node
    2. Visit root
    3. Visit right node

    ==> Time complexity: O(n); n in the number of node.
    ==> Space complexity: O(h); h is the height of the tree. 
            Worst: O(n) 
            Best/Average: O(logn)
*/ 
void Inorder(struct Node *root)
{
    //base case: the tree is empty
    if (root == NULL)
    {
        return; 
    }
    //Otherwise, walk down left subtree, root and right subtree
    Inorder(root -> left);
    printf("%c ", root -> data);
    Inorder(root -> right);
}


/* Post order:
    1. Visit left node
    2. Visit right node
    3. Visit root node

    ==> Time complexity: O(n); n in the number of node.
    ==> Space complexity: O(h); h is the height of the tree. 
            Worst: O(n) 
            Best/Average: O(logn)

*/
void Postorder(struct Node *root)
{
    //base case: the tree is empty:
    if(root == NULL)
    {
        return;
    }
    //Post order traversal
    Postorder(root -> left);
    Postorder(root -> right);
    printf("%c ", root ->data);

}
  