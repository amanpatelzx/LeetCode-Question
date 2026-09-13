class Solution {
public:
    int f(vector<vector<int>> tmp, vector<vector<int>> &img2, set<string> used, int x, int y, set<pair<int,int>>&vis){
        int n = tmp.size();
        if(vis.count({x,y})) return 0;
        vis.insert({x, y});
        int res = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(tmp[i][j] == 1) cnt++;
                if(tmp[i][j] == 1 && img2[i][j] == 1) res++;
            }
        }
        if(cnt == 0) return 0;
        vector<vector<int>> v;
        if(!used.count("right")){
            v.assign(n, vector<int> (n, 0));
            for(int j = 1; j < n; j++){
                for(int i = 0; i < n; i++){
                    v[i][j-1] = tmp[i][j];
                }
            }
            set<string> used1 = used;
            used1.insert("left");
            res = max(res, f(v, img2, used1, x-1, y, vis));
        }
        if(!used.count("left")){
            v.assign(n, vector<int> (n, 0));
            for(int j = 1; j < n; j++){
                for(int i = 0; i < n; i++){
                    v[i][j] = tmp[i][j-1];
                }
            }
            set<string> used1 = used;
            used1.insert("right");
            res = max(res, f(v, img2, used1, x+1, y, vis));
        }
        if(!used.count("up")){
            v.assign(n, vector<int> (n, 0));
            for(int i = 1; i < n; i++){
                for(int j = 0; j < n; j++){
                    v[i][j] = tmp[i-1][j];
                }
            }
            set<string> used1 = used;
            used1.insert("down");
            res = max(res, f(v, img2, used1, x, y-1, vis));
        }
        if(!used.count("down")){
            v.assign(n, vector<int> (n, 0));
            for(int i = 1; i < n; i++){
                for(int j = 0; j < n; j++){
                    v[i-1][j] = tmp[i][j];
                }
            }
            set<string> used1 = used;
            used1.insert("up");
            res = max(res, f(v, img2, used1, x, y+1, vis));
        }
        return res;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        set<string> used;
        set<pair<int,int>> vis;
        return f(img1, img2, used, 0, 0, vis);
    }
};