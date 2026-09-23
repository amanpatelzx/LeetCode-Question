class Solution {
public:
    #define ll long long
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<ll> A(n), B(n);
        A[0] = nums[0];
        B[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            A[i] = A[i-1] + nums[i];
        }
        for(int i = n-2; i >= 0; i--){
            B[i] = B[i+1] + nums[i];
        }
        reverse(B.begin(), B.end());
        int res = INT_MAX;
        for(int i = 0; i < n; i++){
            int left = i;
            int L = 0;
            if(i != 0) L = A[i-1];
            ll curr = x - L;
            if(x == L){
                res = min(res, left);
            }
            auto it = lower_bound(B.begin(), B.begin() + n - left, curr);
            if(it != B.end()){
                int idx = it - B.begin();
                if(B[idx] != curr || idx > n-left-1) continue;
                else{
                    res = min(res , left + idx + 1);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};