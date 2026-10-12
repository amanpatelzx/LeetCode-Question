
class Solution {
public:
    #define ll long long
    int maxSum(vector<int>& nums, int k) {
        ll M = 1e9 + 7;
        vector<int> cnt(31, 0);

        for(int x : nums){
            for(int i = 0; i < 31; i++){
                if(x & (1LL << i)) cnt[i]++;
            }
        }
        ll ans = 0;
        for(int i = 0; i < k; i++){
            ll x = 0;
            for(int j = 0; j < 31; j++){
                if(cnt[j] > 0){
                    x |= (1LL << j);
                    cnt[j]--;
                }
            }
            ans = (ans + x*x) % M;
        }
        return ans;
    }
};
