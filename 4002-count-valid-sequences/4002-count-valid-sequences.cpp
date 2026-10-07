class Solution {
public:
    #define ll long long
    ll M = 1e9 + 7;

    ll f(ll a, ll b){
        if( b == 0) return 1;
        ll tmp = f(a, b/2);
        tmp = (tmp * tmp) % M;
        if(b % 2 == 1) tmp = (tmp * a) % M;
        return tmp;
    }

    ll fact(ll n){
        ll res = 1;
        for(ll i = 1; i <= n; i++){
            res = (res * i) % M;
        }
        return res;
    }
    ll ncr(ll n, ll r){
        ll num = fact(n);
        ll den1 = fact(n-r);
        ll den2 = fact(r);
        ll den = (den1 * den2) % M;
        ll res = f(den, M-2);
        res = (res * num) % M;
        return res;
    }
    int countValidSequences(int n, int k) {
        ll total = ncr(n -1, k-1);
        ll odd = 0;
        if((n-k) % 2 == 0){
            ll N = (n - k) / 2;
            odd = ncr(N + k - 1, k-1);
        }
        ll ans = (total - odd + M) % M;
        return ans;
    }
};