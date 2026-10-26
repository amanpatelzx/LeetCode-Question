class Solution {
public:
    #define ll long long
    int n, m;
    vector<vector<int>> vis;
    ll f(vector<vector<int>>&grid, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;
        if(grid[i][j] == 0) return 0;
        if(vis[i][j] == 1) return 0;
        vis[i][j] = 1;
        ll res = grid[i][j];
        res += f(grid, i+1, j);
        res += f(grid, i-1, j);
        res += f(grid, i, j+1);
        res += f(grid, i, j-1);
        return res;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<int>(m, 0));
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    if(f(grid, i, j) % k == 0) res++;
                }
            }
        }
        return res;
    }
};