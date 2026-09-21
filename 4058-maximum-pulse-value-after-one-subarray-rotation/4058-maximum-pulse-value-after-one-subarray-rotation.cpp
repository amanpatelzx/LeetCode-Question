class Solution {
public:
    #define ll long long
    const ll INF = 1e17;
    ll dp[100005][2][2][2];
    ll f(vector<int> &nums, int i, int take, int ok, int posi){
        if(i >= nums.size() && take && posi ) return -1e15;
        if(i >= nums.size()) return 0LL;
        if(dp[i][take][ok][posi] < INF) return dp[i][take][ok][posi];
        ll res = -1e15;
        ll val = nums[i];
        if(i % 2 == 1) val = -val;
        if(!ok){
            if(take){
                if(!posi){
                    res = max(res , val + f(nums, i+1, 0, 1, 0));
                    res = max(res , -val + f(nums, i+1, 1, 0, 1));
                }
                else{
                    res = max(res , -val + f(nums, i+1, 1, 0, 0));
                }
            }
            else{
                res = max(res , val + f(nums, i+1, take , ok, 0));
                res = max(res , -val + f(nums, i+1, 1, 0, 1));
            }
        }
        else{
            res = max(res , val + f(nums, i+1, take, ok , posi));
        }
        return dp[i][take][ok][posi] = res;
    }
    long long maxValue(vector<int>& nums) {
        memset(dp, 0x3f, sizeof(dp));
        return f(nums, 0, 0, 0, 0);
    }
};