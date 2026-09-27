class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        int n = s.size();
        int i = 0;
        while( i < n){
            if(s[i] != ')'){
                st.push(string(1, s[i]));
            }
            else{
                string tmp;
                while(!st.empty()){
                    if(st.top() == "("){
                        st.pop();
                        st.push(tmp);
                        // cout<<tmp<<" \n";
                        break;
                    }
                    reverse(st.top().begin(), st.top().end());
                    tmp += st.top();
                    st.pop();
                }

            }

            i++;
        }
        string res;
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        // reverse(res.begin(), res.end());
        return res;
    }
};