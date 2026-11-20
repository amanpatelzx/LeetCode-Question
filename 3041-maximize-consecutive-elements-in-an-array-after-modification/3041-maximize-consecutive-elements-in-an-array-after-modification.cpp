
class Solution {
public:
    int n;
    int dp[100004][2][2];
    int f(vector<int> &nums, int i, bool ok, bool prev){
        if(i >= n) return 0;
        if(dp[i][ok][prev] != -1) return dp[i][ok][prev];
        int res = 0;
        if(ok){
            int last = nums[i-1];
            if(prev) last++;
            if(nums[i] - last == 1){
                res = max(res, 1 + f(nums, i+1, 1, 0));
            }
            if(nums[i] == last){
                res = max(res, 1 + f(nums, i+1, 1, 1));
            }
            if(nums[i] == nums[i-1]){
                res = max(res, f(nums, i+1, 1, prev));
            }
        }
        else{
            res = max(res, f(nums, i+1, 0, 0));
            res = max(res, 1 + f(nums, i+1, 1, 0));
            res = max(res, 1 + f(nums, i+1, 1, 1));
        }
        return dp[i][ok][prev] = res;
    }

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));
        return f(nums, 0, 0, 0);
    }
};
