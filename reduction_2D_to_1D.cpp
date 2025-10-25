class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = INT_MIN;
        for(int top = 0; top < n; top++) {
            vector<int> col(m, 0);
            for(int bottom = top; bottom < n; bottom++) {
                for(int i = 0; i < m; i++) col[i] += matrix[bottom][i];

                set<int> prefix; prefix.insert(0);
                int curSum = 0;
                for(int x:col) {
                    curSum += x;
                    auto it = prefix.lower_bound(curSum - k);
                    if(it != prefix.end()) res = max(res, curSum - *it);
                    prefix.insert(curSum);
                }
            }
        }

        return res;
    }
};

