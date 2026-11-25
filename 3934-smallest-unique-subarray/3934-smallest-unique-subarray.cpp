class Solution {
public:
    #define ll long long
    ll f(ll a, ll b, ll M){
        if(b == 0) return 1 % M;
        if(b == 1) return a % M;
        ll tt = f(a, b / 2, M) % M;
        tt = (tt * tt) % M;
        if(b % 2 == 1) tt = ((a % M) * tt) % M;
        return tt;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n;
        int res = n;
        ll base = *max_element(nums.begin(), nums.end()) + 1;
        ll m = 1e9 + 7;
        base %= m;

        vector<ll> power(n + 1, 1);
        for(int i = 1; i <= n; i++){
            power[i] = (power[i-1] * base) % m;
        }

        auto check = [&](int mid){
            map<ll,int> mp;
            ll curr = 0;
            for(int i = 0; i < mid; i++){
                ll term = ((1LL*nums[i] % m) * power[i]) % m;
                curr = (curr + term) % m;
            }
            mp[(curr * power[n]) % m]++;

            for(int i = mid; i < n; i++){
                ll last = nums[i-mid];
                ll sub = ((1LL*last % m) * power[i-mid]) % m;
                curr = ((curr - sub) % m + m) % m;

                ll add = ((1LL*nums[i] % m) * power[i]) % m;
                curr = (curr + add) % m;
                int start = i - mid + 1;
                mp[(curr * power[n-start]) % m]++;
            }
            for(auto &ele : mp){
                if(ele.second == 1) return true;
            }
            return false;
        };
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(mid)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};