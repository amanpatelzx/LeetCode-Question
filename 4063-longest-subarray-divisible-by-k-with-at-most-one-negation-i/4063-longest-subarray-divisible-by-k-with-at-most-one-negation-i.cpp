class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int sum = 0;
            set<int> s;
            for(int j = i; j < n; j++){
                sum = ((sum+nums[j]) % k + k) % k;
                int val = ((2*nums[j]) % k + k) % k;
                s.insert(val);
                if(sum == 0 || s.count(sum)) res = max(res, j-i+1);
            }
        }
        return res;
    }
};