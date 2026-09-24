class Solution {
public:
    vector<vector<int>> res;
    void f(int curr, int k , int n, vector<int> &v){
        if(n == 0 && k == 0){
            res.push_back(v);
            return;
        }
        if(n < 0 || k < 0 || curr > 9) return;
        v.push_back(curr);
        f(curr+1, k-1, n - curr, v);
        v.pop_back();
        f(curr+1, k , n, v);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        f(1, k, n, v);
        return res;
    }
};