#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define ii pair<int,int>
#define fi first 
#define se second 
int n, m;
vector<int> adj[1000005];
vector<bool> visited;
vector<int> topo;

void nhap() {
    cin >>  m;
    visited.resize(n+1, false);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
}

void dfs(int u) {
    visited[u] = true;
    for(int x: adj[u]) {
        if(!visited[x]) dfs(x);
    }
    topo.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    nhap();
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) dfs(i);
    }

    reverse(topo.begin(), topo.end());
    for(int x:topo) cout << x << " " ;

}

// 7 7
// 1 2
// 2 3
// 2 4
// 3 5
// 4 5
// 1 6
// 7 6