class Solution {
public:
    #define ll long long
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ll prod = 1;
                ll lcm = 1;
                ll gcd = 0;
                for(int k = i; k <= j; k++){
                    if(prod > 1e8) break;
                    prod *= 1LL*nums[k];
                    gcd = __gcd(gcd, 1LL*nums[k]);
                    lcm = (lcm * nums[k])/ (__gcd(lcm , 1LL*nums[k]));
                }
                if(prod == lcm * gcd){ 
                    res = max(res , j-i+1);
                    //cout<<prod<<" -> "<<j-i+1<<"\n";
                }
            }
        }
        return res;
    }
};