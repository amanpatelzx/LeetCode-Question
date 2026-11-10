class Solution {
public:
    int dp[1004][1004];
    int f(string &s1, string &s2, int i, int j){
        if(i >= s1.size() || j >= s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;
        if(s1[i] == s2[j]){
            res = max(res, 1 + f(s1, s2, i+1, j+1));
        }
        else{
            res = max(res , f(s1, s2, i+1, j));
            res = max(res , f(s1, s2, i, j+1));
        }
        
        return dp[i][j] = res;
    }
    int longestCommonSubsequence(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        int ans = f(s1, s2, 0, 0);
        return ans;
    }
};