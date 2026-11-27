class Solution {
public:
    unordered_map<int,int> mp;
    int mini;
    vector<vector<int>> dp;
    int f(vector<vector<int>>&v, int bud, int i){
        int n = v.size();
        if(i >= n){
            return bud/mini;
        }
        // if(bud < 0) return -1e5;
        if(dp[i][bud] != -1) return dp[i][bud];
        int res = INT_MIN;
        if(bud >= v[i][1]) res = max(res, mp[v[i][0]] + 1 + f(v, bud-v[i][1],i+1));
        res = max(res, f(v, bud,i+1));
        return dp[i][bud] = res;
    }
    int maximumSaleItems(vector<vector<int>>& v, int bud) {
        mp.clear();
        int n = v.size();
        mini = INT_MAX;
        for(int i = 0; i < n; i++){
            int a = v[i][0];
            mini = min(mini, v[i][1]);
            if(mp.count(a)) continue;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                int val = v[j][0];
                if(val % a == 0) mp[a]++;
            }
        }
        dp.resize(n+2, vector<int>(bud+2,-1));
        return f(v,bud,0);
    }
};