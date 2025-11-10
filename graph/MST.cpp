#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct edge {
  int x, y, w;
};
vector<edge> E;
int n, m;
int parent[1005], sz[1005];
int cc;

void nhap() {
  cin >> n >> m;
  for(int i = 0; i < m ;i++) {
    int x, y, w; cin >> x >> y >> w;
    E.push_back({x, y, w});
  }
}
void init() {
    for(int i = 1; i <= n; i++) {parent[i] = i; sz[i] = 1;}
}

int Find(int u) {
    if(u != parent[u]) return parent[u] = Find(parent[u]);
    return u;
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    // cc--;
    return true;
}

void Kruskal(){
    vector<edge> MST; 
    int d = 0; 
    sort(E.begin(), E.end(), [](edge x, edge y)->bool{
        return x.w < y.w; 
    });
    for(auto e : E){
        if(MST.size() == n - 1) break; 
        
        if(Union(e.x, e.y)){
            MST.push_back(e);
            d += e.w;
        }
    }
    
    if(MST.size() < n - 1){
        cout << "Graph is not connected" << endl;
    }
    else{
        cout << d << endl; 
        for(auto e : MST){ 
            cout << e.x << " " << e.y << " " << e.w << endl;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    nhap();
    init();
    Kruskal();
    return 0;
}
