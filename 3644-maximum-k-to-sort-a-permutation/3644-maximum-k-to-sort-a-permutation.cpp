class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1;
        int n = nums.size();
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            v[nums[i]] = i;
        }
        for(int i = 0; i < n; i++){
            int idx = v[i];
            if(nums[i] != i){
                k = (k & (nums[i] & i));
                v[nums[i]] = idx;
                nums[idx] = nums[i];
                nums[i] = i;
            }
        }
        return k == -1 ? 0 : k;
    }
};