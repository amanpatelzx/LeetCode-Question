class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long res = 0;
        long long target = nums[n/2];
        for(int j = 0; j < n; j++){
            res += abs(target - nums[j]);
        }
      
        return res;
    }
};