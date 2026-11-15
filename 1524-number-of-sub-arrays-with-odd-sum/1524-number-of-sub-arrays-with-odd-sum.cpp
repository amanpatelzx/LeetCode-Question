class Solution {
public:
    #define ll long long
    int n;
    ll M = 1e9 + 7;
    ll dp[100004][2][2];
    ll f(vector<int> & arr, int i, int ok1, int ok2){
        if(i >= n){
            return 1LL*ok2;
        }
        if(dp[i][ok1][ok2] != -1 ) return dp[i][ok1][ok2];
        ll res = 0;
        if(ok1){     
            if(ok2){
                res += (1LL + f(arr, i+1, ok1, 1 - arr[i])) % M;
            }
            else{
                res += (f(arr, i+1, ok1, arr[i]) % M);
            }
        }
        else{
            res += (f(arr, i+1, 1, arr[i]) % M);
            res += (f(arr, i+1, 0, 0) % M);
        }
        return dp[i][ok1][ok2] = res % M;
    }
    int numOfSubarrays(vector<int>& arr) {
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++){
            if(arr[i] % 2 == 0) arr[i] = 0;
            else arr[i] = 1;
        }
        return f(arr, 0, 0, 0);
    }
};