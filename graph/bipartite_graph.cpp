#include <bits/stdc++.h>
using namespace std;
#define int long long
#define input(file) freopen(file, "r", stdin)
#define output(file) freopen(file, "w", stdout)
#define ii pair<int,int>
#define fi first 
#define se second  
int team[1000005]; 
vector<int> adj[1000005];
int n, m; 

bool dfs(int x, int color) {
  team[x] = color;

  for(int v:adj[x]) {
    if(team[v] == 0) {
      if(!dfs(v, 3 - color)) return false;
    } else if(team[v] == color) return false;
  }

  return true;
}
 
signed main() { 
  // input("IN.TXT");
  // output("OUT.TXT");
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int x, y; cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for(int i = 1; i <= n; i++) {
    if(team[i] == 0) {
      if(!dfs(i, 1)) {cout << "IMPOSSIBLE"; return 0;}
    }
  }

  for(int i = 1; i <= n ;i++) cout << team[i] << " " ; 
  return 0;
}