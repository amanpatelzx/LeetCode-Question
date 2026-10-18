class Solution {
public:
    #define ll long long
    int n;
    ll dp[1004][1004];
    ll mod = 1e9 + 7;

    ll f(vector<int> &arr){
        int m = arr.size();
        if(m <= 2) return 1;
        
        vector<int> left, right;
        int a = arr[0];
        for(int i = 1; i < m; i++){
            if(arr[i] < a){
                left.push_back(arr[i]);
            }
            else{
                right.push_back(arr[i]);
            }
        }
        
        ll ans = dp[m-1][left.size()];
        ans = (ans * f(left)) % mod;
        ans = (ans * f(right)) % mod;
        return ans;
    }

    int numOfWays(vector<int>& nums) {
        n = nums.size();
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
            dp[i][i] = 1;
            for(int j = 1; j < i; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
            }
        }
        
        ll ans = f(nums);
        return (ans - 1 + mod) % mod;
    }
};