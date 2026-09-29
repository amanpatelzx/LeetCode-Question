class Solution {
public:
    int dp[102][102][206];
    bool f(vector<vector<char>> & grid, int i , int j, int sum){
        if(sum < 0) return false;
        if(i >= grid.size() || j >= grid[0].size()) return false;
        if(sum == 0 && i == grid.size()-1 && j == grid[0].size()-1) return true;
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        bool result = false;

        if(i + 1 < grid.size()){
            int tt = 1;
            if(grid[i+1][j] != '(') tt = -1;
            result |= f(grid, i+1, j , sum + tt);
        }
        if(j + 1 < grid[0].size()){
            int tt = 1;
            if(grid[i][j+1] != '(') tt = -1;
            result |= f(grid, i, j+1 , sum + tt);
        }
        return dp[i][j][sum] = result;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sum = -1;
        if(grid[0][0] == '(') sum = 1;
        memset(dp, -1, sizeof(dp));
        return f(grid, 0 , 0, sum);
    }
};