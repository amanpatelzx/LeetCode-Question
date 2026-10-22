class Solution {
public:
    int f(vector<int> &nums){
        int n = nums.size();
        bool lof = 0, rok =0;
        int lcnt = 0,rcnt = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] != 1) lcnt++;
            if(nums[i] - nums[i-1] != -1) rcnt++;
        }
        int lres = INT_MAX, rres = INT_MAX;
        // cout<<lcnt<<" "<<rcnt<<"\n";
        if(lcnt == 1){
            int idx;
            for(int i = 0; i <n; i++)if(nums[i] == 0){idx = i; break;}
            lres = idx;
        }
        if(rcnt == 1){
            int idx;
            for(int i = 0; i <n; i++)if(nums[i] == 0){idx = i; break;}
            rres = idx+1+1;
            reverse(nums.begin(),nums.end());
            for(int i = 0; i <n; i++)if(nums[i] == 0){idx = i; break;}
            rres = min(rres, 1+idx);
        }
        if(lcnt > 1 && rcnt > 1) return -1;
        return min(lres, rres);
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        vector<int> v1 = nums;
        sort(v.begin(),v.end());
        if(v == nums) return 0;
        reverse(v1.begin(),v1.end());
        if(v1 == v) return 1;
        if(n == 1) return 0;

        return min(f(nums), f(v1)+1);
        
    }
};