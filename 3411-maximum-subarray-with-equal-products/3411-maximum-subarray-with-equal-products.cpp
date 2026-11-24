class Solution {
public:
    #define ll long long
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            ll prod = 1;
            ll lcm = 1;
            ll gcd = 0;
            for(int j = i; j < n; j++){
                if(prod > 1e8) break;
                prod *= 1LL*nums[j];
                gcd = __gcd(gcd, 1LL*nums[j]);
                lcm = (lcm * nums[j])/ (__gcd(lcm , 1LL*nums[j]));
                if(prod == lcm * gcd){ 
                    res = max(res , j-i+1);
                    //cout<<prod<<" -> "<<j-i+1<<"\n";
                }
            }
        }
        return res;
    }
};