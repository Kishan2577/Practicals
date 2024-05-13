// Flight management: There are flight paths between cities. If there is a 
// flight between city A and city B then there is an edge between the cities. 
// The cost of the edge can be the time that flight takes to reach city B from 
// A, or the amount of fuel used for the journey. 
// Write a menu driven C++ program to represent this as a graph using 
// adjacency matrix and adjacency list. The node can be represented by the 
// airport name or name of the city. Check whether cities are connected 
// through flight or not. Compare the storage representation.

// Name : Harish Lukare
// Roll no: 35
// Div: A
#include<iostream>
#include<list>
using namespace std;
class Graph
{
public:
	int V;
	list <int> *l;
	int i=0;
	int *visited;
	int mat[3][3];
	string *city;
	Graph(int V)
	{
		this->V=V;
		l=new list<int>[V];
		city=new string[V];
		visited=new int[V];
		for(int l=0;l<V;l++)
		{
			for(int m=0;m<V;m++)
			{
				mat[l][m]=0;
			}
		}
	}
	void addEdge(int x,int y)
	{
		visited[i]=x;
		i++;
		visited[i]=y;
		i++;
		mat[x][y]=1;
		l[x].push_back(y);
	}
	void printEdge()
	{
		for(int l=0;l<V;l++)
		{
			
			for(int m=0;m<V;m++)
			{
				if(l==0 && m==0)
				{
					cout<<city[m]<<" ";
				}
				if(l==1 && m==0)
				{
					cout<<city[m]<<" ";
				}
				if(l==2 && m==0)
				{
					cout<<city[m]<<" ";
				}
				cout<<mat[l][m]<<"\t";
			}
			cout<<endl;
		}
		for(int i=0;i<V;i++)
		{
			cout<<"Vertices "<<city[i]<<"->";
			for(int a:l[i])
			{
				cout<<city[a]<<",";
			}
			cout<<endl;
		}
	}
	void isolated(int c)
	{
		int j=0;
		for(int k=0;k<c;k++)
		{
			bool check=true;
			for(int b=0;b<c;b++)
			{
				if(visited[b]==k)
				{
					check=false;
				}
			}
			if(check)
			{
				cout<<city[k]<<" is Isolated"<<endl;
			}
		}
	}
	void addCity()
	{
		for(int i=0;i<V;i++)
		{
			cout<<"Enter the City Name "<<i+1<<" -:";
			cin>>city[i];
		}
		for(int j=0;j<V;j++)
		{
			cout<<"The City "<<city[j]<<" Called it as -:"<<j<<endl;
		}
	}
};
int main()
{
	int A;
	cout<<"Enter the Number of City -:";
	cin>>A;
	Graph g(A);
	int choice=0;
	while(choice!=5)
	{
		
		cout<<"Enter 1.Name The City\nEnter 2.Add the Path\nEnter 3.View the Routes\nEnter 4.Exit"<<endl;
		cout<<"Enter the Choice -:";
		cin>>choice;
		switch(choice)
		{
			case 1:g.addCity();
				break;
			case 2:while(true)
				{
					int b;
					cout<<"Enter 1. Add Edge\n"<<"Enter 2.Exit\n";
					cin>>b;
					int v,w;
					if(b==1)
					{
						cout<<"Enter the Source -:";
						cin>>v;
						cout<<"Enter the Destination -:";
						cin>>w;
						g.addEdge(v,w);
					}
					if(b==2)
					{
						break;
					}
				}
				break;
			case 3:g.printEdge();
				g.isolated(A);
				break;
			case 4:exit(0);
				break;
		}
	}
}
