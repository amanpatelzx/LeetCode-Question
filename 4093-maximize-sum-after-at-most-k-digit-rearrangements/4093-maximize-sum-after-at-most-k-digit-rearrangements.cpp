class Solution {
public:
    #define ll long long
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(n);
        ll res = 0;
        for(int i = 0; i < n; i++){
            string s = to_string(nums[i]);
            sort(s.rbegin(), s.rend());
            ll A = stoll(s);
            v.push_back(A - nums[i]);
            res += nums[i];
        }
        sort(v.rbegin(), v.rend());
        for(int i = 0; i < k; i++){
            res += v[i];
        }
        return res;
    }
};