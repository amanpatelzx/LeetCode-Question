class Solution {
public:
    void print(vector<vector<int>> &v){
        int n = v.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                cout<<v[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int> (n, 1));
        for(int i = 0; i < mines.size(); i++){
            int a = mines[i][0];
            int b = mines[i][1];
            grid[a][b] = 0;
        }

        vector<vector<int>> up(n, vector<int> (n, 0));
        vector<vector<int>> down = up;
        vector<vector<int>> left = up;
        vector<vector<int>> right = up;

        for(int i = 0; i < n; i++){
            int curr = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) curr++;
                else curr = 0;
                left[i][j] = curr;
            }
        }
        for(int i = 0; i < n; i++){
            int curr = 0;
            for(int j = n-1; j >= 0; j--){
                if(grid[i][j] == 1) curr++;
                else curr = 0;
                right[i][j] = curr;
            }
        }
        for(int j = 0; j < n; j++){
            int curr = 0;
            for(int i = n-1; i >= 0; i--){
                if(grid[i][j] == 1) curr++;
                else curr = 0;
                up[i][j] = curr;
            }
        }
        for(int j = 0; j < n; j++){
            int curr = 0;
            for(int i = 0; i < n; i++){
                if(grid[i][j] == 1) curr++;
                else curr = 0;
                down[i][j] = curr;
            }
        }

        int res = 0;
        if(mines.size() != n*n) res = 1;
        for(int i = 0; i < n; i++){
            if(i-1 < 0 || i+1 == n) continue;
            for(int j = 0; j < n; j++){
                if(j-1 < 0 || j+1 == n) continue;
                if(grid[i][j] == 0) continue;
                int l = left[i][j-1];
                int r = right[i][j+1];
                int u = up[i+1][j];
                int d = down[i-1][j];
                
                int k = min({l, r, u, d});
                //if(k == 2) cout<<i<<" "<<j<<"\n";
                res = max(res, k+1);
            }   
        }
        // print(grid);
        // print(up);
        // print(down);
        // print(left);
        // print(right);
        return res;
    }
};