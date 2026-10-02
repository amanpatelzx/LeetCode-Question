class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(auto &ele : nums) s.insert(ele);
        vector<int> v;
        for(auto &ele : s) v.push_back(ele);
        if(v.size() < 3) return v.back();
        else return v[v.size()-3];
    }
};