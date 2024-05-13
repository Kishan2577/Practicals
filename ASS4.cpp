#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }

};


Node* insert(int key,Node *root)
{
    Node *n = new Node(key);
    if(root == NULL)
    {
        return n;
    }

    if(key<root->data)
    {
        root->left = insert(key,root->left);
    }
    else if(key>root->data)
    {
        root->right = insert(key,root->right);
    }
    return root;
}
void display(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<" "<<root->data<<endl;
    display(root->left);
    display(root->right);
    return;
}
bool search(int key, Node *root)
{

    if(root == NULL)
    {
        return false;
    }
    if(root->data == key )
    {
        return true;
    }
    
    if(root->data > key)
    {
        return search(key,root->left);
    }
        
    return search(key,root->right);

}
int minimum(Node *root)
{
    if(root->left == NULL)
    {
        return root->data;
    }
    
    int d =   minimum(root->left);
    return d;
}
void asec(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    asec(root->left);
    cout<<" "<<root->data;
    asec(root->right);
}
void dsec(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    dsec(root->right);
    cout<<" "<<root->data;
    dsec(root->left);
}
int longestPath(Node *root,int depth)
{
    if(root == NULL)
    {
        return 0;
    }

    int leftlength = longestPath(root->left,depth+1);
    int rightlength = longestPath(root->right,depth+1);
    return max(leftlength,rightlength)+1;
}
int main()
{
    int key;
    Node *ROOT = NULL;
    ROOT = insert(10,ROOT);
    ROOT = insert(50,ROOT);
    ROOT = insert(20,ROOT);
    ROOT = insert(15,ROOT);
    ROOT = insert(60,ROOT);
    ROOT = insert(80,ROOT);
    ROOT = insert(5,ROOT);
    ROOT = insert(95,ROOT);
    cout<<"ENTER THE ELEMENT TO FIND"<<endl;
    cin>>key;
    if(search(key,ROOT))
    {
        cout<<"ELEMENT FOUND"<<endl;
    }
    else 
    {
        cout<<"ELEMENT NOT FOUND"<<endl;
    }
    
    int min = minimum(ROOT);
    cout<<"MINIMUM VALUE "<<min<<endl;
    cout<<"ASCENDING"<<endl;
    asec(ROOT);
    cout<<"DESCENDING"<<endl;
    dsec(ROOT);
    int long1 = longestPath(ROOT,0);
    cout<<"LONGEST PATH = "<<long1<<endl;
    return 0;
}