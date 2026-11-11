class Solution {
public:
    #define ll long long
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        cost1 = min(cost1, costBoth);
        cost2 = min(cost2, costBoth);
        if(costBoth >= cost1 + cost2){
            return 1LL*need1*cost1 + 1LL*need2*cost2;
        }
        ll n = min(need1, need2);
        ll ans = 1LL*n*costBoth;
        if(need1 > need2){
            ans += 1LL*(need1 - need2)*cost1;
        }
        else{
            ans += 1LL*(need2 - need1)*cost2;
        }
        return ans;
    }
};