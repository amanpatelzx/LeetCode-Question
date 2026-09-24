class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int val = nums[i];
            int sum = 0;
            while(val){
                sum += val % 10;
                val /= 10;
            }
            if(sum == i) return i;
        }
        return -1;
    }
};