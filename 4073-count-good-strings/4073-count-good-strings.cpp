class Solution {
public:
    #define ll long long
    int M = 1e9 + 7;
    pair<ll, ll> fib (ll n) {
        if (n == 0) return {0, 1};
        auto p = fib(n >> 1);
        ll c = (p.first * ((2 * p.second - p.first + M) % M)) % M;
        ll d = ((p.first * p.first) % M + (p.second * p.second) % M) % M;
        if(n & 1) return {d, (c + d) % M};
        else return {c, d};
    }
    int countGoodStrings(long long n) {
        return (2 * fib(n).first) % M;
    }
};