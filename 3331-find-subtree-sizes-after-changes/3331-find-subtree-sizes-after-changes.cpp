
class Solution {
public:
    vector<int> v;
    void dfs(int u, vector<vector<int>>& g, vector<int>& parent1, vector<int>& parent, string &s){
        int c = s[u] - 'a';
        int prev = v[c];
        if(v[c] != -1) parent1[u] = v[c];
        else parent1[u] = parent[u];
        v[c] = u;
        for(int v : g[u]){
            dfs(v, g, parent1, parent, s);
        }
        v[c] = prev;
    }

    void dfs2(int u, vector<vector<int>>& g, vector<int>& ans){
        for(int v : g[u]){
            dfs2(v, g, ans);
            ans[u] += ans[v];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        v.resize(26 , -1);
        int n = parent.size();
        vector<vector<int>> g(n), g1(n);

        for(int i = 1; i < n; i++){
            g[parent[i]].push_back(i);
        }

        vector<int> parent1(n, -1);
        dfs(0, g, parent1, parent, s);

        for(int i = 1; i < n; i++){
            g1[parent1[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        dfs2(0, g1, ans);
        return ans;
    }
};
