class Solution {
public:
    int dp[100004][2][2];
    int f(string &s, int i, bool parity, bool choosen){
        if(i >= s.size()){
            if(!parity) return 0;
            else return 1e7;
        }
        if(dp[i][parity][choosen] != -1) return dp[i][parity][choosen];

        int res = 1e7;
        if(!parity){
            res = min(res , (s[i] - '0') + f(s, i+1, 1, 0));
            res = min(res , 1-(s[i] - '0') + f(s, i+1, 1, 1));
        }
        else{
            if(choosen){
                res = min(res , 1-(s[i] - '0') + f(s, i+1, 0, 0));
            }
            else{
                res = min(res , (s[i] - '0') + f(s, i+1, 0, 0));
            }
        }

        return dp[i][parity][choosen] = res;
    }

    int minChanges(string s) {
        memset(dp, -1, sizeof(dp));
        return f(s, 0, 0, 0);
    }
};