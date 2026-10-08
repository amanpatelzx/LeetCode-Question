class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string res;
        int cnt = 0;
        int last = 1;
        string tmp;
        for(int i = 1; i < n; i++) {
            if(s[i] == '(') cnt++;
            else cnt--;
            if(cnt == -1){
                res += tmp;
                i++;
                cnt = 0;
                tmp = "";
            }
            else tmp += s[i];
        }
        return res;
    }
};