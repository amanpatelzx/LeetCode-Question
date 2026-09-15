class Solution {
public:
    int pali[2002][2002];
    bool is_pali(string &s, int i , int j){
        if(i > j) return true;
        if(pali[i][j] != -1) return pali[i][j];
        if(s[i] != s[j]) return pali[i][j] = false;
        return pali[i][j] = is_pali(s, i+1, j-1);
    }
    int dp[2002][2002][4];
    bool f(string &s, int i, int last, int cnt){
        if(last >= s.size() || i >= s.size()) return false;
        if(cnt == 1){
            return dp[i][last][cnt] = is_pali(s, last, s.size()-1);
        }
        if(dp[i][last][cnt] != -1) return dp[i][last][cnt];
        bool res = f(s, i+1, last, cnt);
        if(is_pali(s, last, i)){
            res |= f(s, i+1, i+1, cnt-1);
        }
        return dp[i][last][cnt] = res;
    }
    bool checkPartitioning(string s) {
        memset(dp, -1, sizeof(dp));
        memset(pali, -1, sizeof(pali));
        return f(s, 0, 0, 3);
    }
};