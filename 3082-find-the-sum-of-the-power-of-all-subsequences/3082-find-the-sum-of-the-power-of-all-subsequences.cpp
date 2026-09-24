class Solution {
public:
    #define ll long long
    ll M = 1e9 + 7;
    ll dp[102][102][102];
    ll f2(ll a, ll b){
        if(b == 0) return 1;
        ll tmp = f2(a, b/2);
        tmp = (tmp * tmp) % M;
        if(b % 2 == 1) tmp = (a * tmp) % M;
        return tmp % M;
    }
    ll f(vector<int> &nums, int i, int cnt , int k){
        int n = nums.size();
        if(k == 0){
            ll val = n - cnt;
            val = f2(2, val);
            return val;
        }
        if(i >= n || k < 0) return 0;
        if(dp[i][cnt][k] != -1) return dp[i][cnt][k];
        ll res = 0;
        res += f(nums, i+1, cnt, k);
        res += f(nums, i+1, cnt+1, k - nums[i]);
        return dp[i][cnt][k] = res % M;
    }
    int sumOfPower(vector<int>& nums, int k) {
        memset(dp, -1 , sizeof(dp));
        return f(nums, 0, 0, k);
    }
};