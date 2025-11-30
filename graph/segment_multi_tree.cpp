#include <iostream>
#include <string>
#include <vector>
#define int long long
#define ii pair<int,int>
#define fi first 
#define se second
#define pb push_back
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)  
using namespace std;
#define input(file) freopen(file, "r", stdin);
#define output(file) freopen(file, "w", stdout);
long long a[2000005];
long long t[10][4000005];  
int n, q;

bool solve(long long index, int k) {
    if (index == 0) return false; 

    long long temp = index;
    while (temp > 0) {
        if (temp % 10 == k) return true;
        temp /= 10;
    }
    return false;
}

long long cal(int a_val, int index, int k) {

    if(index % k == 0) return a_val * 2;
    else if (solve(index, k)) return a_val * 2;

    return a_val;
}

void build(int _k, int v, int l, int r) {
    if(l == r) t[_k][v] = cal(a[l], l, _k);
    else {
        int mid = (l + r) / 2;
        build(_k, v * 2, l, mid);
        build(_k, v * 2 + 1, mid + 1, r);
        t[_k][v] = t[_k][v * 2] + t[_k][v * 2 + 1];
    }
}

void update(int _k, int v, int l, int r, int pos, int val) {
    if(l == r) t[_k][v] = cal(val, l, _k);
    else {
        int mid = (l + r) / 2;
        if(pos <= mid) update(_k, v * 2, l, mid, pos, val);
        else update(_k, v * 2 + 1, mid + 1, r, pos, val);
        t[_k][v] = t[_k][v*2] + t[_k][v * 2 + 1];
    }
}

int query(int _k, int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l == tl && r == tr) return t[_k][v];

    int tm = (tl + tr)/2;
    return query(_k, v * 2, tl, tm, l, min(r, tm)) +
           query(_k, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);

}



signed main() {
    // input("../IN.TXT");
    // output("../OUT.TXT");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int k = 1; k <= 9; k++) build(k, 1, 1, n);
    // for(int i = 1; i <= n * 2 + 1; i++) cout << t[i] << " " ;    
    while(q--) {
        int x; cin >> x;
        if(x == 1) {
            int i, c; cin >> i >> c;
            for(int k = 1; k <= 9; k++) update(k, 1, 1, n, i, c);
        } else {
            int L, R, k; cin >> L >> R >> k;
            cout << query(k, 1, 1, n, L, R) << endl;
        }
    }
    
    return 0;
}
