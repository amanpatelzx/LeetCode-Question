class Solution {
public:
    int dp[302][302];
    int f(vector<int> &nums, int l ,int r){
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int left = 1, right = 1;
        if(l-1 >= 0) left = nums[l-1];
        if(r+1 < nums.size()) right = nums[r+1];
        int res = 0;
        for(int x = l; x <= r; x++){
            res = max(res, f(nums, l, x-1) + f(nums, x+1, r) + left*nums[x]*right);
        }
        return dp[l][r] = res;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return f(nums, 0, nums.size()-1);
    }
};