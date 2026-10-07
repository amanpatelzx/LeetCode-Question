class Solution {
public:
    vector<string> res;
    int n;
    void f(string &s, int i, string &tmp, int left, int right){
        if(i == n){
            if(left == right){
                res.push_back(tmp);
            }
            return;
        }
        if(s[i] == '('){
            tmp += s[i];
            f(s, i+1, tmp, left+1, right);
            tmp.pop_back();
            f(s, i+1, tmp, left, right);
        }
        else if(s[i] == ')'){
            if(right+1 <= left){
                tmp += s[i];
                f(s, i+1, tmp, left, right+1);
                tmp.pop_back();
            }
            f(s, i+1, tmp, left, right);
        }
        else{
            tmp += s[i];
            f(s, i+1, tmp, left, right);
            tmp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        string tmp;
        f(s, 0, tmp, 0, 0);
        int maxi = 0;
        int m = res.size();
        for(int i = 0; i < m; i++){
            int M = res[i].size();
            maxi = max(maxi ,M);
        }
        set<string> S;
        vector<string> ans;
        for(int i = 0; i < m; i++){
            int M = res[i].size();
            if(M == maxi) S.insert(res[i]);
        }
        for(auto &ele : S) ans.push_back(ele);
        return ans;
    }
};