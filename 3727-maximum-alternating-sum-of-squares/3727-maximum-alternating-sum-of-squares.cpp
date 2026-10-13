class Solution {
public:
    #define ll long long
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end() , [&](auto a, auto b){
            if(abs(a) > abs(b)) return true;
            else return false;
        });
        ll even = 0, odd = 0;
        if(n & 1){
            for(int i = 0; i < n; i++){
                if(i <= n/2) even += 1LL*nums[i]*nums[i];
                else odd += 1LL*nums[i]*nums[i];
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(i < n/2) even += 1LL*nums[i]*nums[i];
                else odd += 1LL*nums[i]*nums[i];
            }
        }
        return even - odd;
    }
};