class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1;
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            bool ok = 0;
            int cnt = 2;
            if(nums[i] < nums[i+1]){
                ok = 1;
            }
            else if(nums[i] == nums[i+1]){
                continue;
            }
            res = max(res ,cnt);
            for(int j = i+2; j < n; j++){
                if(ok){
                    if(nums[j] > nums[j-1]){
                        cnt++;
                        res = max(res, cnt);
                    }
                    else {
                        res = max(res, cnt);
                        break;
                    }
                }
                else{
                    if(nums[j] < nums[j-1]){
                        cnt++;
                        res = max(res, cnt);
                    }
                    else{
                        res = max(res, cnt);
                        break;
                    }
                }
                
            }
        }
        return res;
    }
};