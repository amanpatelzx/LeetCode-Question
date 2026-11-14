class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res = 1e6;
        int n = nums.size();
        int curr = 0;
        for(int len = l; len <= r; len++){
            curr = 0;
            for(int i = 0; i < len; i++){
                curr += nums[i];
            }
            int last = 0;
            if(curr > 0) res = min(res, curr);
            for(int i = len; i < n; i++){
                curr += nums[i];
                curr -= nums[last];
                last++;
                if(curr > 0) res = min(res, curr);
            }

        }
        return res == 1e6 ? -1 : res;
    }
};