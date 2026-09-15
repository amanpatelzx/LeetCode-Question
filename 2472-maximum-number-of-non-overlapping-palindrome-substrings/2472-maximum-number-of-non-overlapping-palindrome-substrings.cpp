class Solution {
public:
    int pali[2002][2002];
    bool is_pali(string &s, int i, int j){
        if(i > j) return true;
        if(pali[i][j] != -1) return pali[i][j];
        if(s[i] != s[j]) return pali[i][j] = false;
        return pali[i][j] = is_pali(s , i+1, j-1);
    }
    int dp[2002][2002];
    int f(string &s, int k , int i, int last){
        int n = s.size();
        if(i >= n) return 0;
        if(dp[i][last] != -1) return dp[i][last];
        int res = 0;
        if(is_pali(s ,last, i)){
            // cout<<last<<" "<<i<<" \n";
            res = max(res , 1 + f(s, k ,i+k , i+1));
        }
        res = max( res, f(s, k, i+1, last));
        res = max( res, f(s, k, last+k, last+1));

        return dp[i][last] = res;
    }
    int maxPalindromes(string s, int k) {
        memset(pali, -1, sizeof(pali));
        memset(dp, -1, sizeof(dp));
        // cout<<is_pali(s, 0, 2)<<"\n";
        // cout<<is_pali(s, 1, 3)<<"\n";
        return f(s, k, k-1, 0);
    }
};