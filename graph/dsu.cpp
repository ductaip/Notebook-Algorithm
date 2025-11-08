#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod;
int n, q;
int parent[1005], sz[1005];
int cc;
void init() {
    cin >> n >> q;
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
    cc--;
    return true;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init(); cc = n;
    while(q--) {
        string s; cin >> s;
        if(s == "U") {
            int x, y; cin >> x >> y;
            Union(x, y);
        } else if(s == "Q") {
            int x, y; cin >> x >> y;
            if(Find(x) == Find(y)) cout << "YES" << endl;
            else cout << "NO" <<endl;
        } else if(s == "SZ") {
            int x; cin >> x;
            cout << sz[Find(x)] << endl;
        } else cout << cc << endl;
    }

    return 0;
}
