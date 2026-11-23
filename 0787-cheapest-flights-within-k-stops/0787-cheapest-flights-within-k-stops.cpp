class Solution {
public:
    vector<vector<pair<int,int>>> g;
    int dp[102][102];
    int f(int node, int dst, int k){
        if(k < 0) return 1e8;
        if(node == dst){
            return 0;
        }
        if(dp[node][k] != -1) return dp[node][k];
        int res = 1e8;
        for(auto &ele : g[node]){
            res = min(res , ele.second + f(ele.first, dst, k-1));
        }

        return dp[node][k] = res;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        g.resize(n+1);
        for(auto &ele : flights){
            int from = ele[0];
            int to = ele[1];
            int price = ele[2];
            g[from].push_back({to, price});
        }
        memset(dp, -1, sizeof(dp));
        int ans = f(src, dst, k+1);
        return ans >= 1e8 ? -1 : ans;
    }
};