class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        map<string,string> mp;
        for(auto &it : knowledge){
            mp[it[0]] = it[1];
        }
        string res;
        bool ok = false;
        string last;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                ok = 1;
            }
            else if(s[i] ==')'){
                ok = 0;
                if(mp.count(last)){
                    res += mp[last];
                }
                else{
                    res += '?';
                }
                last = "";
            }
            else if(ok){
                last += s[i];
            }
            else if(!ok){
                res += s[i];
            }
        }
        return res;
    }
};