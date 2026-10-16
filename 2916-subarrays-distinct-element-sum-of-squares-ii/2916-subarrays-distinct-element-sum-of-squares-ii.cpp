class Solution {
public:
    #define ll long long
    ll M = 1e9 + 7;
    int n;
    vector<ll> sum, sumSq, lazy;

    void lazyAddition(int i, int l, int r, int val){
        ll len = r - l + 1;
        sumSq[i] = (sumSq[i] + 2LL * val * sum[i] + len * val * val) % M;
        sum[i] = (sum[i] + len * val) % M;
    }

    void update(int ql, int qr, int i, int l, int r, int val){
        if(lazy[i] != 0){
            ll x = lazy[i];
            lazyAddition(i, l, r, x);

            if(l != r){
                lazy[2 * i + 1] += x;
                lazy[2 * i + 2] += x;
            }

            lazy[i] = 0;
        }

        if(l > qr || r < ql || l > r) return;

        if(ql <= l && r <= qr){
            lazyAddition(i, l, r, val);

            if(l != r){
                lazy[2 * i + 1] += val;
                lazy[2 * i + 2] += val;
            }
            return;
        }

        int mid = (l + r) / 2;

        update(ql, qr, 2 * i + 1, l, mid, val);
        update(ql, qr, 2 * i + 2, mid + 1, r, val);

        sum[i] = (sum[2 * i + 1] + sum[2 * i + 2]) % M;
        sumSq[i] = (sumSq[2 * i + 1] + sumSq[2 * i + 2]) % M;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sum.assign(4 * n, 0);
        sumSq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> last(100001, -1);
        ll ans = 0;

        for(int i = 0; i < n; i++){
            int l = last[nums[i]] + 1;
            update(l, i, 0, 0, n - 1, 1);
            ans = (ans + sumSq[0]) % M;
            last[nums[i]] = i;
        }
        return ans;
    }
};