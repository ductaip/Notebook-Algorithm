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
string longestPalindromicSubstring(string s) {
    int n = s.length();
    if (n < 2) {
        return s;
    }

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int start = 0; 
    int maxLen = 1;  

    //baseline 1
    for (int i = 0; i < n; ++i) dp[i][i] = true;

    //baseline 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1; 

            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                if (len > maxLen) {
                    start = i;
                    maxLen = len;
                }
            }
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    cout << longestPalindromicSubstring("babad") << endl;
    cout <<  longestPalindromicSubstring("cbbd") << endl;
    return 0;
}