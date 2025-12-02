#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
#define ii pair<int,int>
#define fi first 
#define se second
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)  
using namespace std;
#define input(file) freopen(file, "r", stdin);
#define output(file) freopen(file, "w", stdout);
char a[2000][2000];
int h[2000005], s[2000005];
int dp[100005];  
int n, m, x;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = { 0, -1, 1,  0};

void solve() {
  FOR(i, 1, n) {
    RFOR(j, x, h[i]) {
      // dp[i][j] = dp[i-1][j];

      dp[j] = max(dp[j], dp[j-h[i]] + s[i]);
    }
  }

  cout << dp[x];
}

signed main() {
    // input("./IN.TXT");
    // output("./OUT.TXT");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> h[i];    
    for(int i = 1; i <= n; i++) cin >> s[i]; 
    solve();   
    
    return 0;
}
