#include <bits/stdc++.h>
using namespace std;
#define int long long
#define input(file) freopen(file, "r", stdin)
#define output(file) freopen(file, "w", stdout)
#define ii pair<int,int>
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i <= b; i++)

 
long long w[MAXN]; 

//select / not select
void dfs(int u, int p) {
    dp[u][0] = 0;
    dp[u][1] = w[u]; 

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);

        dp[u][0] += max(dp[v][0], dp[v][1]);  
        dp[u][1] += dp[v][0];                 
    }
}

int ans = 0;

//Tree Diameter 
void dfs(int u, int p) {
    int max1 = 0;  
    int max2 = 0;  

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        
        int len_v = dp[v] + 1; 

        if (len_v > max1) {
            max2 = max1;
            max1 = len_v;
        } else if (len_v > max2) {
            max2 = len_v;
        }
    }

    ans = max(ans, max1 + max2);

    dp[u] = max1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // input("IN.TXT");
    // output("OUT.TXT");
    dfs();
}