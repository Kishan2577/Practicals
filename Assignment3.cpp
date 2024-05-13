// Activity on vertex(AOV) network: Sandy is a well organized person. 
// Every day he makes a list of things which need to be done and 
// enumerates them from 1 to n. However, some things need to be done 
// before others. Write a C++ code to find out whether Sandy can solve all 
// his duties and if so, print the correct order

// Name : Harish Lukare
// Roll no: 35
// Div: A
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class DiGraph {
    unordered_map<int, list<int>> adjList;  

public:

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    vector<int> topologicalSort() {
        unordered_map<int, int> indegree;  
        list<int> queue;  

        for (auto& pair : adjList) {
            indegree[pair.first] = 0;
        }

        for (auto& pair : adjList) {
            for (int v : pair.second) {
                indegree[v]++;
            }
        }

        for (auto& pair : adjList) {
            if (indegree[pair.first] == 0) {
                queue.push_back(pair.first);
            }
        }

        vector<int> topologicalOrder;
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop_front();
            topologicalOrder.push_back(u);

            for (int v : adjList[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    queue.push_back(v);
                }
            }
        }

        if (topologicalOrder.size() != adjList.size()) {
            cout << "Sandy cannot solve all his duties as there is a cycle in the graph." << endl;
            exit(1);
        }

        return topologicalOrder;
    }
};

int main() {
    DiGraph g;
    int Number;
    cout<<"How many Number of Edges -: ";
    cin>>Number;
    for(int i=0;i<Number;i++)
    {
    	int f,s;
    	cout<<"From Edge -: ";
    	cin>>f;
    	cout<<"To Edge -: ";
    	cin>>s;
    	g.addEdge(f,s);
    	
    }
    vector<int> topologicalOrder = g.topologicalSort();

    cout << "The correct order of tasks is: ";
    for (int i : topologicalOrder) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
