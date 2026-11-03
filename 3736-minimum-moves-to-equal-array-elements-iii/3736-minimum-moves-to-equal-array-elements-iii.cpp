class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int res = 0;
        for(auto &ele : nums){
            res += maxi - ele;
        }
        return res;
    }
};