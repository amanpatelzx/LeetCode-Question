class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else{
                if(st.empty()) return false;
                else{
                    char ch = st.top();
                    if(s[i] == ')' && ch != '(') return false; 
                    if(s[i] == '}' && ch != '{') return false; 
                    if(s[i] == ']' && ch != '[') return false; 
                    st.pop();
                }
            }
        }
        return st.size() == 0;
    }
};