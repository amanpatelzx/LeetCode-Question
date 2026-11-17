class Solution {
public:
    int dp1[202][202][102];
    int f3(string &s, int start, int end, int d){
        if(dp1[start][end][d] != -1) return dp1[start][end][d];
        int N = end - start + 1;
        int cost = 0;
        for(int i = 0; i < d; i++){
            string tt;
            for(int j = i; j < N; j += d){
                tt.push_back(s[start + j]);
            }
            int a = 0, b = tt.size()-1;
            //cout<<tt<<"\n";
            while(a < b){
                if(tt[a] != tt[b]){
                    cost++;
                }
                a++;
                b--;
            }
        }
        return dp1[start][end][d] = cost;
    }
    int f2(string &s, int start, int end){
        int N = end - start + 1;
        if(N == 1) return 1e5;
        int res = 1e6;
        for(int i = 1; i*i <= N; i++){
            if(N % i == 0){
                res = min(res, f3(s, start, end, i));
                if(i != 1){
                    res = min(res , f3(s, start, end, N/i));
                }
            } 
        }
        return res;
    }

    int dp[202][202][102];
    int f(string &s, int k, int i, int last){
        //if(k*1.0 < ((int)(s.size())*1.0 )/ 2) return 1e6;
        if(k == 1) return f2(s, last, s.size()-1);
        if(i == s.size()-1 && k > 1) return 1e6;

        if(dp[i][last][k] != -1) return dp[i][last][k];
        int res = 1e9;
        res = min(res, f(s, k, i+1, last));
        res = min(res , f2(s, last, i) + f(s, k-1, min((int)s.size()-1, i+2) ,i+1));

        return dp[i][last][k] = res;
    }

    int minimumChanges(string s, int k) {
        memset(dp, -1, sizeof(dp));
        memset(dp1, -1, sizeof(dp));
        return f(s, k , min((int)s.size()-1, 1),0);
    }
};