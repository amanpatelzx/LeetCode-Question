class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int n = strs.size();
        int i = 0;
        int sizeLimit = 5000;
        for(auto &ele : strs){
            sizeLimit = min(sizeLimit , (int)ele.size());
        }
        for(int i = 0; i < sizeLimit; i++){
            char ch = strs[0][i];
            bool ok = true;
            for(auto &ele : strs){
                if(ele[i] != ch){
                    ok = false;
                    break;
                }
            }
            if(ok) res.push_back(ch);
            else break;
        }
        return res;
    }
};