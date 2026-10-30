class Solution {
public:
    #define F first
    #define S second
    vector<vector<pair<int,int>>> g;
    string s;
    int f(int k, int n){
        vector<int> dis(n, 1e9);
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{0,1}});
        while(!pq.empty()){
            auto tt = pq.top();
            int x = tt.S.F;
            int d = tt.F;
            int cnt = tt.S.S;
            pq.pop();
            
            if(cnt >= dis[x]) continue;
            dis[x] = cnt;
            if(x == n-1) return -d;
            for(auto &v : g[x]){
                int neigh = v.F;
                int cost = v.S;
                int val = 1;
                if(s[x] == s[neigh]) val = cnt + 1;
                if(val <= k) pq.push({-(-d + cost), {neigh, val}});
            }
        }
        return -1;
    }
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        g.resize(n);
        s = labels;
        for(auto &ele : edges){
            int u = ele[0];
            int v = ele[1];
            int w = ele[2];
            g[u].push_back({v,w});
        }
        int ans = f(k, n);
        return ans;
    }
};