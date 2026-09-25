class Solution {
public:
    void f(string &s, int &i, set<string> &ans){
        set<string> curr;
        while(i < s.size() && s[i] != '}'){
            if(s[i] == ','){
                for(auto &x : curr) ans.insert(x);
                curr.clear();
                i++;
            }
            else if(s[i] == '{'){
                i++;
                set<string> temp;
                f(s, i, temp);
                i++;
                
                if(curr.empty()) curr = temp;
                else{
                    set<string> next;
                    for(auto &a : curr){
                        for(auto &b : temp){
                            next.insert(a + b);
                        }
                    }
                    curr = next;
                }
            }
            else{
                string x = "";
                x += s[i];
                i++;
                
                if(curr.empty()) curr.insert(x);
                else{
                    set<string> next;
                    for(auto &a : curr) next.insert(a + x);
                    curr = next;
                }
            }
        }
        for(auto &x : curr) ans.insert(x);
    }
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans;
        f(expression, i, ans);
        vector<string> res;
        for(auto &ele : ans) res.push_back(ele);
        return res;
    }
};