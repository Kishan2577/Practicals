#include<iostream>
#include<vector>
using namespace std;

class Node
{
    public:
    string city1;
    string city2;
    Node *next;
    Node(string c1,string c2)
    {
        city1 = c1;
        city2 = c2;
        next = NULL;
    }
};

class Graph
{
    public:
    string city;
    Node *head=NULL;
};

Graph arr[10];
int size = 1;

void add(string city1,string city2)
{
    Node *n = new Node(city1,city2);
    for(int i=0;i<=size;i++)
    {
        if(arr[i].head == NULL)
        {
            arr[i].city = city1;
            arr[i].head = n;
            size++;
            return;
        }
        else if(arr[i].head!=NULL && arr[i].city == city1)
        {
            Node *temp = arr[i].head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
            size++;
            return;
        }
        
    }

}
void display()
{
    for(int i=0;i<size;i++)
    {
        cout<<" "<<arr[i].city<<" ";
        Node *t = arr[i].head;
        while(t!=NULL)
        {
            cout<<" -> "<<t->city2<<" ";
            t = t->next;
        }
        cout<<endl;
    }
    return;
}

int main()
{
    int i=0;
    string c1,c2;
    int chose;

    do
    {

    cout<<"1) ENTER THE EDGE"<<endl;
    cout<<"2) DISPLAY ALL CITIES "<<endl;
    cout<<"3)CHECK THE CONNECTION "<<endl;
    cout<<"4) EXIT"<<endl;
    cin>>chose;
    switch(chose)
    {
        case 1:
            cout<<"ENTER CITY 1"<<endl;
            cin>>c1;
            cout<<"ENTER CITY 2"<<endl;
            cin>>c2;
            add(c1,c2);
            
            break;

        case 2: 
            cout<<" ADJACENCY LIST "<<endl;
            display();
            break;

        case 3:
            break;

        case 4: 
            cout<<"EXITING...."<<endl;
            i=1;

    }    

    }while(i==0);
    return 0;
}