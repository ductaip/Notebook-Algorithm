#include <iostream>
#include <vector>
#include <queue>
#include <utility> 

using namespace std;
 
#define ii pair<int, int>
#define se second 
#define fi first
int n, m, s; 
vector<ii> adj[1005]; 

void nhap() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void dijkstra() {
    priority_queue<ii, vector<ii>, greater<ii>> q;

    vector<int> d(n + 1, 1e9);

    d[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        ii t = q.top(); q.pop();

        int dis = t.fi, u = t.se;  

        if (dis > d[u]) continue;

        for (ii e : adj[u]) {
            int v = e.fi;  
            int w = e.se; 

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i] << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    nhap();      
    dijkstra();  
    return 0;
}