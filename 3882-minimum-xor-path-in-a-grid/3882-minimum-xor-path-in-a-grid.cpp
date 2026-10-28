class Solution {
public:
    vector<vector<vector<int>>> dp;
    void f(vector<vector<int>> &grid, int i , int j , int &ans ,int temp){
        if(i >= grid.size() || j >= grid[0].size()) return;
        if(i == grid.size()-1 && j == grid[0].size()-1){
            temp = (temp^grid[i][j]);
            ans = min(ans, temp);
            return;
        }
        temp = (temp^grid[i][j]);
        if(dp[i][j][temp] != -1) return;
        dp[i][j][temp] = 1;
        f(grid , i+1 , j , ans, temp);
        f(grid , i , j+1 , ans, temp);
    }
    int minCost(vector<vector<int>>& grid) {
        dp.resize(grid.size()+1 , vector<vector<int>>(grid[0].size()+1 , vector<int>(1024, -1)));
        int ans = INT_MAX;
        f(grid, 0 , 0 , ans , 0);
        return ans;
    }
};