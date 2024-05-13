// Binary search tree: Write a menu driven C++ program to construct a 
// binary search tree by inserting the values in the order give, considering at 
// the beginning with an empty binary search tree, After constructing a 
// binary tree. Insert new node, ii. Find number of nodes in longest path from root, iii. 
// Minimum data value found in the tree iv. Search a value v. Print values 
// in ascending and descending order

// Name : Harish Lukare
// Roll no: 35
// Div: A
#include<iostream>
using namespace std;
class Node
{
public:
Node *left;
int data;
Node *right;
Node()
{
	this->left=NULL;
	 data=0;
	 this->right=NULL;
}
};
void insertion(Node *root,int value)
{
	Node *newNode=new Node;
	newNode->data=value;
	if(root->data==0)
	{
		root->data=value;
	}
	else{
		if(value<root->data)
		{
			if(root->left==NULL)
			{
				root->left=newNode;
			}
			else
			{
				insertion(root->left,value);
			}
		}
		else{
			if(root->right==NULL)
			{
				root->right=newNode;
			}
			else
			{
				insertion(root->right,value);
			}
		}
	}
}
void searching(Node *root,int key)
{
	if(root->data==key)
	{
		cout<<"We find the key -:"<<root->data<<endl;
		return;
	}
	if(root->data!=key && root->left==NULL && root->left==NULL)
	{
		cout<<"Data is not in BST\n";
		return;
	}
	else{
		if(key<root->data)
		{
			searching(root->left,key);
		}
		else{
			searching(root->right,key);
		}
	}
}
void ascending(Node *root)
{
	if(root==NULL)
		return;
	ascending(root->left);
	cout<<root->data<<" ";
	ascending(root->right);
}
int maxheight(Node *root)
{
	if(root==NULL)
	return 0;
	int lheight=maxheight(root->left);
	int rheight=maxheight(root->right);
	if(lheight>rheight)
	{
		return(lheight+1);
	}
	else
	{
		return(rheight+1);
	}
}
void min_value(Node* root)
{
	if(root->left==NULL)
	{
		cout<<"Minimum value -:"<<root->data<<" \n";
		return;
	}
	ascending(root->left);
	
}
void descending(Node *root)
{
	if(root==NULL)
		return;
	descending(root->right);
	cout<<root->data<<" ";
	descending(root->left);
}
void Delete(Node *root,int key,Node *prev)
{
	Node *temp=root;
	Node* pre=prev;
	if(temp->data==key)
	{
		if(temp->left==NULL && temp->right==NULL)
		{
			if(pre->left==temp)
			{
				pre->left=NULL;
			}
			else
			{
				pre->right=NULL;
			}
			delete temp;
			cout<<"Delete Succesfully\n";
			return;
		}
		if(temp->left!=NULL && temp->right!=NULL)
		{
			Node *t=temp->right;
			if(t->left==NULL)
			{
				temp->data=t->data;
				temp->left=t->left;
				temp->right=t->right;
				delete t;
				cout<<"Delete Succesfully\n";
				return;
			}
			else
			{
				Node *t1=t;
				while(t->left==NULL)
				{
					t1=t;
					t=t->left;
				}
				if(pre->left==temp)
				{
					pre->left=t1;
				}
				else
				{
					pre->right=t1;
				}
				t1->left=NULL;
				t->left=temp->left;
				t->right=temp->right;
				delete temp;
				cout<<"Delete Succesfully\n";
				return;
			}
		}
		if(temp->left!=NULL || temp->right!=NULL)
		{
			if(temp->left!=NULL)
			{
				Node *t=temp->left;
				temp->data=t->data;
				temp->left=t->left;
				temp->left=t->right;
				delete t;
				cout<<"Delete Succesfully\n";
				return;
			}
			if(temp->right!=NULL)
			{
				Node *t=temp->right;
				temp->data=t->data;
				temp->left=t->left;
				temp->left=t->right;
				delete t;
				cout<<"Delete Succesfully\n";
				return;
			}
		}
	}
	if(temp->data!=key && temp->left==NULL && temp->left==NULL)
	{
		cout<<"Data is not in BST\n";
		return;
	}
	else{
		if(key<temp->data)
		{
			Node *pre=temp;
			Delete(temp->left,key,pre);
		}
		else{
			Node *pre=temp;
			Delete(temp->right,key,pre);
		}
	}
}
int main()
{
	Node *root=new Node;
	int choice =0;
	while(choice!=8)
	{
	cout<<"Enter 1 : For Inserting the Data in BST\n"<<"Enter 2 : For Searching the Data in BST\n"<<"Enter 3 : Ascending Order\n"<<"Enter 4 : Descending Order\n"<<"Enter 5 : Height of Tree\n"<<"Enter 6 : Minimum Value\n"<<"Enter 7 : Delete\n"<<"Enter 8 : Exit\n"<<"Enter the choice -:";
	cin>>choice;
	switch(choice)
	{
		case 1: int temp;
			cout<<"Enter the Number of Data -:";
			cin>>temp;
			for(int i=0;i<temp;i++)
			{
				int data;
				cout<<"Enter Data -:";
				cin>>data;
				insertion(root,data);
				cout<<"Added Succesfully!!\n";
			}
			break;
		case 2: int key;
			cout<<"Enter the Data to be Search -:";
			cin>>key;
			searching(root,key);
			break;
		case 3: ascending(root);
			cout<<endl;
			 break;
		case 4: descending(root);
			cout<<endl;
			 break;
		case 5: cout<<"Height of the Tree is -: "<<maxheight(root)<<endl;
			break;
		case 6: min_value(root);
			break;
		case 7:int key1;
			cout<<"Enter Key Which is Need To be Deleted -:";
			cin>>key1;
			Delete(root,key1,NULL);
	}
	}
	cout<<"Signing out!!!\n ";
}
