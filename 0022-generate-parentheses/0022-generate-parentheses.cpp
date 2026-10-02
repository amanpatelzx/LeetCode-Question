class Solution {
public:
    vector<string> res;
    int N;
    void f(int left, int n, string &s){
        if(n == 0 && left == 0){
            res.push_back(s);
        }
        if(left > N || n < 0) return;
        s.push_back('(');
        f(left + 1, n, s);
        s.pop_back();

        if(left > 0){
            s.push_back(')');
            f(left-1, n-1, s);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        N = n;
        string s;
        f(0, n, s);
        return res;
    }
};