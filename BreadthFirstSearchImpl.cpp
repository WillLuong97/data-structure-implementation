/* Binary tree - Level Order Traversal */ 
#include<iostream>
using namespace std; 
#include<queue>
struct Node{ 
    char data; 
    Node *left;
    Node *right;


};

//Function to traverse through a tree:
void levelOrder(Node *root)
{
    //if the tree is empty, nothing here to see:
    if(root == NULL)
    {
        return; 
    }

    //creating a queue that would be storing the Node variables:
    queue<Node*> Q;
    Q.push(root); 
    //While there is at least one discovered node
    while(!Q.empty())
    {
        Node* current = Q.front();
        cout << current -> data << "";
        if(current -> left != NULL){
            Q.push(current -> left);
        }

        if(current -> right != NULL)
        {
            Q.push(current -> right);
        }

        Q.pop(); //removing the element at the front, or the parent node once the child nodes are added

    }

}//end of levelOrder().

Node* Insert(Node *root, char data)
{
    //if the tree is empty, adding the data to the root:
    if(root == NULL)
    {
        root = new Node();
        root -> left = root -> right = NULL;
        root -> data = data;
    }

    //if the tree already has element, add to the right subtree if the data is greater than the root 
    // and to the left if the data is lesser
    else if(data <= root -> data)
    {
        //make a recursive call until the data is in the left
        root -> left = Insert(root -> left, data);
    }

    else
    {
        root -> right = Insert(root -> right, data);
    }
    
    return root;
}

//main function to test the levelOrder Traversal: 
int main()
{
    Node* root = NULL;
    root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z'); 
	root = Insert(root,'A'); root = Insert(root,'C');
	//Print Nodes in Level Order. 
	levelOrder(root);

}