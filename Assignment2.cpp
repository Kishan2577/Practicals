// Graph traversal: The area around the college and the prominent 
// landmarks of it are represented using graphs. 
// Write a menu driven C++ program to represent this as a graph using 
// adjacency matrix /list and perform DFS and BFS. 

// Name : Harish Lukare
// Roll no: 35
// Div: A
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void addEdge(int **adjMatrix, int u, int v, int vertices)
{
    if (u >= 0 && u < vertices && v >= 0 && v < vertices)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
}

void bfs(int startNode, int **adjMatrix, bool *visited, int vertices)
{
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();

        for (int v = 0; v < vertices; v++)
        {
            if (adjMatrix[u][v] && !visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

void dfs(int startNode, int **adjMatrix, bool *visited, int vertices)
{
    stack<int> stk;
    stk.push(startNode);
    visited[startNode] = true;

    while (!stk.empty())
    {
        int u = stk.top();
        cout << u << " ";
        stk.pop();

        for (int v = 0; v < vertices; v++)
        {
            if (adjMatrix[u][v] && !visited[v])
            {
                stk.push(v);
                visited[v] = true;
            }
        }
    }
}

void printadjMatrix(int **adjMatrix, int vertices)
{
    cout << "The adjacency matrix is :- " << endl;

    cout << "  ";
    for (int i = 0; i < vertices; i++)
    {
        cout << i << " "; 
    }
    cout << endl;

    for (int i = 0; i < vertices; i++)
    {
        cout << i << " "; 

        for (int j = 0; j < vertices; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int vertices, edges;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    int **adjMatrix = new int *[vertices];
    for (int i = 0; i < vertices; i++)
    {
        adjMatrix[i] = new int[vertices]();
    }

    bool *visited = new bool[vertices]();

    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout<<"--------------------------------------------------------"<<endl;
        cout << "Enter the edges (u v):" << endl;
        int u, v;
        cin >> u >> v;
        cout<<"--------------------------------------------------------"<<endl;
        addEdge(adjMatrix, u, v, vertices);
    }

    int startNode;
    cout<<"--------------------------------------------------------"<<endl;
    cout << "Enter the starting node: ";
    cin >> startNode;
    cout<<"--------------------------------------------------------"<<endl;
    cout << "BFS traversal is: ";
    bfs(startNode, adjMatrix, visited, vertices);
    cout << endl;

    
    fill(visited, visited + vertices, false);
    cout<<"--------------------------------------------------------"<<endl;
    cout << "DFS traversal is: ";
    dfs(startNode, adjMatrix, visited, vertices);
    cout << endl;
    cout<<"--------------------------------------------------------"<<endl;
    printadjMatrix(adjMatrix, vertices);
    
    
    return 0;
}
