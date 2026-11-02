class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long avg = nums[n/2];
        int idx = lower_bound(nums.begin(), nums.end(), avg) - nums.begin();

        int lower = max(0, idx - 8);
        int upper = min(n-1, idx+8);
        
        long long res = INT_MAX;
        for(int i = lower; i <= upper; i++){
            long long target = nums[i];
            long long curr = 0;
            for(int j = 0; j < n; j++){
                curr += abs(target - nums[j]);
            }
            res = min(res, curr);
        }
        return res;
    }
};