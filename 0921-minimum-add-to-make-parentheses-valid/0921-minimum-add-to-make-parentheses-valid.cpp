class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        int res = 0;
        for(auto &ch : s){
            if(ch == '(') cnt++;
            else cnt--;
            if(cnt < 0){
                cnt = 0;
                res++;
            }
        }
        return res + cnt;
    }
};