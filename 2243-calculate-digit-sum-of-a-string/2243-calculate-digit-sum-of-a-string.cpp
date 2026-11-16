class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        string tmp;
        int i = 0;
        while(s.size() > k){
            int K = k;
            int val = 0;
            while(K--){
                if(i >= s.size()) break;
                val += s[i] - '0';
                i++;
            }
            tmp += to_string(val);
            if(i >= s.size()){
                s = tmp;
                tmp = "";
                i = 0;
            }
        }
        return s;
    }
};