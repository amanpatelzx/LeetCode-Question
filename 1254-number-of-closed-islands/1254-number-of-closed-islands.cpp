class Solution {
public:
    int n, m;
    vector<vector<int>> vis;
    bool dfs(vector<vector<int>> &grid, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        if(grid[i][j] == 1 || vis[i][j]) return true;
        vis[i][j] = 1;
        bool res = true;
        res &= dfs(grid, i+1, j);
        res &= dfs(grid, i-1, j);
        res &= dfs(grid, i, j+1);
        res &= dfs(grid, i, j-1);

        return res;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        n = grid.size();
        m = grid[0].size();
        vis.resize(n ,vector<int> (m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    if(dfs(grid, i, j)) res++;
                }
            }
        }
        return res;
    }
};