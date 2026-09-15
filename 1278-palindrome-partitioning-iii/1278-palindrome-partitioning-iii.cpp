class Solution {
public:
    int pali(string &s, int i, int j){
        int cnt = 0;
        while(i <= j){
            if(s[i] != s[j]) cnt++;
            i++;
            j--;
        }
        return cnt;
    }
    int dp[102][102][102];
    int f(string &s, int k, int i, int last){
        if(last >= s.size()) return 1e5;
        if(i >= s.size()) return 1e5;
        if(dp[k][i][last] != -1) return dp[k][i][last];
        if(k == 1) return dp[k][i][last] = pali(s, last, s.size()-1);
        int res = f(s, k, i+1, last);
        res = min(res, pali(s, last, i)  + f(s, k-1, i+1, i+1));
        return dp[k][i][last] = res;
    }
    int palindromePartition(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return f(s, k, 0, 0);
    }
};