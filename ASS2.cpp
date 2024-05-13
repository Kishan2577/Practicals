#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Node
{
    public:
    string place1;
    string place2;
    Node *next = NULL;
    Node(string p1,string p2)
    {
        place1 = p1;
        place2 = p2;
    }
};
class Graph
{
    public:
    string place;
    Node *head = NULL;
};
class Visited
{
    public:
    string citycheck;
    bool flag = false;
};
Graph arr[10];
Visited visited[10];
void add(string place1,string place2,int total)
{
    Node *n = new Node(place1,place2);
    for(int i=0;i<total;i++)
    {
        if(arr[i].head!=NULL && arr[i].place == place1)
        {
            Node *temp = arr[i].head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next = n;
            return;
        }
        else if(arr[i].head==NULL)
        {
            arr[i].place = place1;
            arr[i].head = n;
            visited[i].flag = false;
            return;
        }
    }
    return;
}

void display(int total)
{
    cout<<" "<<endl;
    for(int i=0;i<total;i++)
    {
        Node *t = arr[i].head;
        cout<<" "<<arr[i].place;
        while(t!=NULL)
        {
            cout<<" -> "<<t->place2;
            t = t->next;
        }
        cout<<endl;
    }
}
queue<string> q;
void BFS(int total)
{
    for(int i=0;i<total;i++)
    {
        visited[i].citycheck = arr[i].place;
    }
    
    q.push(arr[0].place);
    while(!q.empty())
    {
        
        for(int i=0;i<total;i++)
        {
            if(arr[i].place == q.front())
            {
                visited[i].flag = true;
                Node *temp = arr[i].head;
                while(temp!=NULL)
                {
                    for(int k=0;k<total;k++)
                    {
                        if(visited[k].citycheck == temp->place2 && visited[k].flag == false)
                        {
                            q.push(temp->place2);
                            visited[k].flag=true;
                            break;
                        }
                    }
                    temp = temp->next;

                }
            }
        }
        cout<<" "<<q.front();
        q.pop();

    }

}

void DFS(int total,string start)
{
    
    cout<<" "<<start;
    for(int i=0;i<total;i++)
    {
        if(arr[i].place == start)
        {
            Node *t = arr[i].head;
            while(t!=NULL)
            {
                for(int k=0;k<total;k++)
                {
                    if(visited[k].citycheck == t->place2 && visited[k].flag == false )
                    {
                        visited[k].flag = true;
                        DFS(total,t->place2);
                    }
                }
                t=t->next;
            }
            return;
        }
    }
}


int main()
{
    int total=10;
    add("A","B",total);
    add("B","A",total);
    add("A","C",total);
    add("C","A",total);
    add("B","E",total);
    add("E","B",total);
    add("A","D",total);
    add("D","A",total);
    add("C","F",total);
    add("F","C",total);
    add("D","G",total);
    add("G","D",total);
    display(total);
    BFS(total);
    for(int i=0;i<total;i++)
    {
        visited[i].citycheck = arr[i].place;
        visited[i].flag = false;
    }
    visited[0].flag = true;
    cout<<" "<<endl;
    DFS(total,"A");
    return 0;
}