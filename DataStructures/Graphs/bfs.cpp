#include<bits/stdc++.h>
using namespace std;

// Implementing bfs
// With Adjacency list
vector<vector<int>> adj; // adjacency list representation
int n = 7; // number of nodes
int s = 1; // source vertex

queue<int> q;
vector<bool> used(n);
vector<int> d(n), p(n);

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
    
    s = 1;
    q.push(s);
    used[s] = true;
    p[s] = -1;

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        cout << "Visiting node: " << v << endl;

        for(int u: adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }

    cout << "Lengths " << endl;
    for(int item: d) cout << item << " ";
    cout << "\n";

    cout << "Parents" << endl;
    for(int item: p) cout << item << " ";
    cout << "\n";

    return 0;
}
