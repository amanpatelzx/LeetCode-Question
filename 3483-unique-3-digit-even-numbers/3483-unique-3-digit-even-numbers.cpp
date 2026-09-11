class Solution {
public:
    set<vector<int>> s;
    vector<bool> vis;
    void f(vector<int> &digits, vector<int> &tmp){
        if(tmp.size() == 3){
            if(tmp.front() != 0 && tmp.back() % 2 == 0) s.insert(tmp);
            return;
        }
        for(int i = 0; i < digits.size(); i++){
            if(!vis[i]){
                vis[i] = 1;
                tmp.push_back(digits[i]);
                f(digits , tmp);
                tmp.pop_back();
                vis[i] = 0;
            }
        }
    }
    int totalNumbers(vector<int>& digits) {
        vector<int> tmp;
        vis.resize(12, false);
        f(digits, tmp);
        return s.size();
    }
};