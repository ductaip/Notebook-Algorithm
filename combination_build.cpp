#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int fact[4000005], invfact[4000005];
//https://oj.vnoi.info/problem/olp_ct24_path
int fpow(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

void init(int N) {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i-1] * i % MOD;
    invfact[N] = fpow(fact[N], MOD-2);
    for (int i = N; i > 0; i--) invfact[i-1] = invfact[i] * i % MOD;
}

int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

int cnt(int x1,int y1,int x2,int y2){
    int dx = x2-x1;
    int dy = y2-y1;
    if(dx<0 || dy<0) return 0;
    return C(dx+dy, dx);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n,k;
    cin>>m>>n>>k;

    init(2*(m+n)); 

    vector<pair<int,int>> v(k);
    for(int i=0;i<k;i++) cin>>v[i].first>>v[i].second;

    v.push_back({m,n});
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.first + a.second < b.first + b.second;
    });

    int K = v.size();
    vector<int> dp(K);

    for(int i=0;i<K;i++){
        dp[i] = cnt(1,1, v[i].first, v[i].second);
        for(int j=0;j<i;j++){
            if(v[j].first <= v[i].first && v[j].second <= v[i].second){
                dp[i] = (dp[i] - dp[j] * cnt(v[j].first, v[j].second,
                        v[i].first, v[i].second) % MOD + MOD) % MOD;
            }
        }
    }

    cout<<dp.back();
    return 0;
}
