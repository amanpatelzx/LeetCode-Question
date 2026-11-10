class Solution {
public:
    int dp[100004];
    int f(int &n ,vector<int> &costs, int i){
        if(i >= n) return 0;
        if(dp[i] != -1 ) return dp[i];
        int res = 1e9;
        if(i < n) res = min(res, costs[i] + 1 + f(n, costs, i+1));
        if(i+1 < n) res = min(res, costs[i+1] + 4 + f(n, costs, i+2));
        if(i+2 < n) res = min(res, costs[i+2] + 9 + f(n, costs, i+3));

        return dp[i] = res;
    }
    int climbStairs(int n, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        int res = f(n , costs, 0);
        return res;
    }
};