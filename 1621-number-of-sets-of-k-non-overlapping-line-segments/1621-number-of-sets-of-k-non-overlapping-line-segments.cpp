class Solution {
public:
    #define ll long long
    int M = 1e9 + 7;
    ll dp[1002][1002][2];
    ll f(int n, int k, int i, bool ok){
        if(k == 0) return 1;
        if(i >= n) return 0;
        // if(i < n && k == 1 && ok) return 1;
        if(dp[i][k][ok] != -1) return dp[i][k][ok];
        ll ans = 0;
        if(ok){
            ans = (ans + f(n, k-1, i, 0)) % M;
            ans = (ans + f(n , k , i+1, 1)) % M;
        }
        else{
            ans = (ans + f(n, k, i+1, 1)) % M;
            ans = (ans + f(n , k , i+1, 0)) % M;
        }
        return dp[i][k][ok] = (ans % M);
    }
    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return f(n , k , 0, 0);
    }
};