class Solution {
public:
    #define ll long long
    int m;
    vector<int> cntBit;
    vector<ll> sumBit;

    void update(int idx, int sign, ll val){
        while(idx <= m){
            cntBit[idx] += sign;
            sumBit[idx] += sign * val;
            idx += idx & -idx;
        }
    }

    pair<int, ll> findKth(int k, const vector<int>& arr){
        int idx = 0;
        int curCnt = 0;
        ll sumBefore = 0;

        for(int step = 1 << 17; step > 0; step >>= 1){
            if(idx + step <= m && curCnt + cntBit[idx + step] < k){
                idx += step;
                curCnt += cntBit[idx];
                sumBefore += sumBit[idx];
            }
        }

        ll medianVal = arr[idx];
        ll exactLowSum = sumBefore + (ll)(k - curCnt) * medianVal;

        return {idx, exactLowSum};
    }

    ll dp[16][100005];
    int n, X;

    ll solve(int i, int k, const vector<ll>& c){
        if(k == 0) return 0;
        if(i > n - X) return 1e18;
        if(dp[k][i] != -1) return dp[k][i];

        ll res = solve(i + 1, k, c);
        res = min(res, c[i] + solve(i + X, k - 1, c));

        return dp[k][i] = res;
    }

    ll minOperations(vector<int>& nums, int x, int k){
        n = nums.size();
        X = x;

        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        m = arr.size();

        cntBit.assign(m + 1, 0);
        sumBit.assign(m + 1, 0);

        vector<ll> c(n - x + 1);
        ll totalWindowSum = 0;
        int mid = (x + 1) / 2;

        for(int i = 0; i < n; i++){
            int pos = lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin() + 1;
            update(pos, 1, nums[i]);
            totalWindowSum += nums[i];

            if(i >= x){
                int oldPos = lower_bound(arr.begin(), arr.end(), nums[i-x]) - arr.begin() + 1;
                update(oldPos, -1, nums[i-x]);
                totalWindowSum -= nums[i-x];
            }

            if(i >= x-1){
                auto [medIdx, sumLow] = findKth(mid, arr);
                ll med = arr[medIdx];
                ll sumHigh = totalWindowSum - sumLow;
                int lowCnt = mid, highCnt = x - mid;

                c[i-x+1] = (med * lowCnt - sumLow) + (sumHigh - med * highCnt);
            }
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, k, c);
    }
};
