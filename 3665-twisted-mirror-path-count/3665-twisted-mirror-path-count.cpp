class Solution {
public:
    #define ll long long
    ll M = 1e9+7;
    int n, m;
    ll dp[502][503][2];
    ll f(vector<vector<int>> &grid,int i, int j, int dir){
        if(i == n-1 && j == m-1) return 1;
        if(i >= n || j >= m) return 0;
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        ll res = 0;
        if(dir){//dir true means right
            if(grid[i][j] == 1){
                res += f(grid, i+1, j, 1-dir);
            }
            else{
                res +=f(grid, i+1, j, 0);
                res +=f(grid, i, j+1, 1);
            }
        }
        else{
            if(grid[i][j] == 1){
                res += f(grid, i, j+1, 1-dir);
            }
            else{
                res +=f(grid, i+1, j, 0);
                res +=f(grid, i, j+1, 1);
            }
        }
        return dp[i][j][dir] = res % M;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1,sizeof(dp));
        ll res = f(grid, 0, 0, 0);
        return (int)res;
    }
};