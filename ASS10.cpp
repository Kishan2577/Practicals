#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;



class Node
{
    public:
    string key;
    string value;
    Node *next = NULL;
    Node(string k,string v)
    {
        key = k;
        value = v;
    }
};

Node* arr[10];


int HashFunction(string key)
{
    int sum=1;
    int i=0;
    for(auto ch : key)
    {
        sum = sum + ch;
        i++;
    }   

    return sum%10;
}

void insert(string key,string value)
{
    int index = HashFunction(key);
    Node *n = new Node(key,value);
    if(arr[index] == NULL)
    {
        arr[index] = n;
        cout<<"DATA INSERTED SUCCESSFULLY"<<endl;
        return;
    }
    Node *temp = arr[index];
    while(temp->next!=NULL || temp->key == key)
    {
        if(temp->key == key )
        {
            cout<<"KEY ALREADY PRESENT IN DICTIONARY"<<endl;
            return;
        }
        temp = temp->next;
    }
    temp->next = n;
    cout<<"DATA INSERTED SUCCESSFULLY"<<endl;
    return;
}
void search(string key)
{
    int index = HashFunction(key);
    Node *temp = arr[index];
    while(temp!=NULL)
    {
        if(temp->key == key)
        {
            cout<<"ELEMENT FOUND SUCCESSFULLY"<<endl;
            cout<<"KEY = "<<temp->key<<" VALUE = "<<temp->value<<endl;
        }
        temp = temp->next;
    }
    cout<<"ELEMENT NOT FOUND"<<endl;
    return;
}

int main()
{
    string key;
    for(int i=0;i<10;i++)
    {
        arr[i] = NULL; 
    }
    
    insert("RED","COLOR");
    insert("RED","COLOR");
    insert("ORANGE","FRUIT");
    insert("MANGO","FRUIT");
    insert("POTATO","VEG");
    cout<<"ENTER THE KEY"<<endl;
    cin>>key;
    search(key);
    


    return 0;
}