class Solution {
public:
    #define ll long long
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        ll res = nums.front() + nums.back();
        vector<ll> v;
        for(int i = 1; i < n-1; i++){
            v.push_back(nums[i]);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n-2; i += 2){
            if(i+1 == n-2) break;
            ll curr = v[i] + v[i+1];
            if(curr > 0) break;
            res += curr;
        }
        return res;
    }
};