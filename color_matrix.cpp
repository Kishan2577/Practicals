#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, vector<vector<int>> &graph, vector<int> &colors, int color) {
    for (int adjacent = 0; adjacent < graph.size(); ++adjacent) {
        if (graph[node][adjacent] && colors[adjacent] == color) {
            return false; // if adjacent node has the same color
        }
    }
    return true;
}

bool colorGraph(int node, int m, vector<vector<int>> &graph, vector<int> &colors) {
    if (node == graph.size()) return true; // all nodes are colored

    for (int col = 1; col <= m; ++col) {
        if (isSafe(node, graph, colors, col)) {
            colors[node] = col;

            if (colorGraph(node + 1, m, graph, colors)) return true;

            colors[node] = 0; // backtrack
        }
    }
    return false;
}

void solveGraphColoring(int n, int m, vector<vector<int>> &graph) {
    vector<int> colors(n, 0);

    if (colorGraph(0, m, graph, colors)) {
        cout << "Solution Exists: Following are the assigned colors:\n";
        for (int i = 0; i < n; i++) cout << "Vertex " << i + 1 << " --->  Color " << colors[i] << endl;
    } else {
        cout << "Solution does not exist with " << m << " colors.\n";
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of colors: ";
    cin >> m;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    solveGraphColoring(n, m, graph);
    return 0;
}
