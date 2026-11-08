class Solution {
public:
    bool check(vector<vector<int>> &grid, int row, int col){
        for(int i = 0; i < grid.size(); i++){
            if(i == row) continue;
            if(grid[i][col] == 1) return 1;
        }
        for(int j = 0; j < grid[0].size(); j++){
            if(j == col) continue;
            if(grid[row][j] == 1) return 1;
        }
        return 0;
    }
    int countServers(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1 && check(grid, i , j)) res++;
            }
        }
        return res;
    }
};