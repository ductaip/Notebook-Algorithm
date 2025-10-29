#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define ii pair<int,int>
#define fi first 
#define se second
#define pb push_back
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)  
using namespace std;

long long a[1000005];
long long t[4000005];  
int n, q;

void build(int v, int tl, int tr) {
    if (tl == tr) t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void update(int v, int tl, int tr, int pos, long long new_val) {
    if (tl == tr) t[v] = new_val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(v * 2, tl, tm, pos, new_val);
        else update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

long long query_sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    
    return query_sum(v * 2, tl, tm, l, min(r, tm)) + query_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;  

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    build(1, 0, n - 1);
 
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << query_sum(1, 0, n - 1, l, r) << "\n";
        } else if (type == 2) {
            int pos;
            long long val;
            cin >> pos >> val;
            update(1, 0, n - 1, pos, val);
        }
    }

    return 0;
}
