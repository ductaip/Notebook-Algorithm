#include <bits/stdc++.h>
using namespace std;
#define int long long
#define input(file) freopen(file, "r", stdin)
#define output(file) freopen(file, "w", stdout)
#define ii pair<int,int>
#define fi first 
#define se second  
#define FOR(i, a, b) for(int i = a; i <= b; i++)
const int MAXN = 1e6 + 5;
int dp[5005][5005];
int a[2000005];
int lazy[2000005];
vector<int> t(4 * MAXN, 0);
int n, m; 

void build(int v, int l, int r) {
  if(l == r) t[v] = a[l];
  else {
    int mid = (l + r)/ 2;
    build(v * 2, l, mid);
    build(v * 2 + 1, mid + 1, r);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}

void update(int v, int l, int r, int pos, int val) {
  if(l == r) t[v] = val;
  else {
    int mid = (l + r) / 2;
    if(pos <= mid) update(v * 2, l, mid, pos, val);
    else update(v * 2 + 1, mid + 1, r, pos, val);

    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}

void push(int v, int l, int r) {
  if(lazy[v] != 0) {
    t[v] += (r - l + 1) * lazy[v];

    if(l != r) {
      lazy[v*2] += lazy[v];
      lazy[v*2+1] += lazy[v];
    }
    lazy[v] = 0;
  }
}

void rangeUpdate(int v, int l, int r, int ql, int qr, int val) {
  push(v, l, r);

  if(l > qr || ql > r) return;

  if(ql <= l && r <= qr) {
    lazy[v] += val;
    push(v, l, r);
    return;
  }

  int mid = (l + r) /2 ;
  rangeUpdate(v * 2, l, mid, ql, qr, val);
  rangeUpdate(v * 2 + 1, mid + 1, r, ql, qr, val);
  t[v] = t[v * 2] + t[v * 2 + 1];
}

long long query(int v, int tl, int tr, int l, int r) {
  if(l > r) return 0;
  if(l == tl && r == tr) return t[v];

  int tmid = (tl + tr) /2;
  return query(v * 2, tl, tmid, l, min(r, tmid)) + query(v * 2 + 1, tmid + 1, tr, max(tmid + 1, l), r);
}

long long pointQuery(int v, int l, int r, int pos) {
  push(v, l, r);
  if(l == r) return t[v];
  int tmid = (l + r) /2;
  if(pos <= tmid) return pointQuery(v * 2, l, tmid, pos) ;
  else return pointQuery(v * 2 + 1, tmid + 1, r, pos);
}

signed main() { 
  // input("IN.TXT");
  // output("OUT.TXT");
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  while(m--) {
    int x; cin >> x;
    if(x == 1) {
      int a, b, u; cin >> a >> b >> u;
      rangeUpdate(1, 1, n, a, b, u);
    } else {
      int a; cin >> a;
      cout << pointQuery(1, 1, n, a) << endl;
    }
  }

}