#include<iostream>
using namespace std;

class Node
{
    public:
    char data;
    Node *left;
    Node *right;
    Node(char d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node *root = NULL;
int index = 0;

int search(char in[],char pre[],int start,int end,char value)
{
    for(int i=start;i<end;i++)
    {
        if(in[i]==value)
        {
            return i;
        }
    }
}

Node* InAndPre(char in[],char pre[],int start,int end)
{

    if(start>end)
    {
        return NULL;
    }
    Node *temp = new Node(pre[index]);
    index++;
    if (start == end) 
    {
        return temp;
    }
        
        int loc = search(in,pre,start,end,temp->data);
        temp->left = InAndPre(in,pre,start,loc-1);
        temp->right = InAndPre(in,pre,loc+1,end);
        
        return temp;
    
}

void display(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<" "<<root->data;
    display(root->left);
    
    display(root->right);
    
}


int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
    int len = sizeof(in) / sizeof(in[0]);
    Node *ROOT = InAndPre(in,pre,0,len-1);
    display(ROOT);
    return 0;
}