#include<bits/stdc++.h>
using namespace std;

// Implementing Depth first search
// Adjacency matrix
/*
int nodes = 6;

int adj_m[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 1, 0, 0, 1, 0}, 
                 {0, 1, 0, 1, 0, 1, 0},
                 {0, 0, 1, 0, 1, 0, 0},
                 {0, 0, 0, 1, 0, 1, 1},
                 {0, 1, 1, 0, 1, 0, 0},
                 {0, 0, 0, 0, 1, 0, 0}};

int visited[7];

void dfs(int node) {
    cout << "Visiting node " << node << endl;
    visited[node] = 1;
    for(int i = 1; i<= nodes; ++i) {
        if(adj_m[node][i] !=  0 && visited[i] == 0) 
            dfs(i);
    }
}
*/

// Adjacency list
vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices

vector<bool> visited(7);

void dfs(int v) {
    cout << "Visiting node " << v << endl;
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}

int main() {
    vector<int> tmp{0};
    adj.push_back(tmp);
    tmp.clear();
    
    tmp = {2, 5}; 
    adj.push_back(tmp);
    tmp.clear();

    tmp = {1, 3, 5};
    adj.push_back(tmp);
    tmp.clear();

    tmp = {2, 4};
    adj.push_back(tmp);
    tmp.clear();

    tmp = {3, 5, 6};
    adj.push_back(tmp);
    tmp.clear();

    tmp = {1, 2, 4};
    adj.push_back(tmp);
    tmp.clear();

    tmp = {4};
    adj.push_back(tmp);
    tmp.clear();

    dfs(1);
    
    return 0;
}
