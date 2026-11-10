class Solution {
public:
    int n, m;
    int dp[503][503];
    int f(string &word1, string &word2, int i, int j){
        if(i >= n && j >= m) return 0;
        if(i >= n){
            return m-j;
        }
        if(j >= m) return n - i;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 1e6;
        if(word1[i] == word2[j]) res = f(word1, word2, i+1, j+1);
        else{
            res = min(res, 1 + f(word1, word2, i+1, j));
            res = min(res, 1 + f(word1, word2, i, j+1));
        }
        return dp[i][j] = res;
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        n = word1.size();
        m = word2.size();
        return f(word1, word2, 0, 0);
    }
};