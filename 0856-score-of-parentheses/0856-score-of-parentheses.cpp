class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<pair<int,int>> st;
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == '('){
                st.push({0, 0});
            }
            else{
                if(st.top().first == 0){
                    st.pop();
                    st.push({2, 1});
                }
                else{
                    int sum = 0;
                    while(st.top().first != 0){
                        sum += st.top().second;
                        st.pop();
                    }
                    st.pop();
                    st.push({2, sum*2});
                }
            }
        }
        int res = 0;
        while(!st.empty()){
            res += st.top().second;
            st.pop();
        }
        return res;
    }
};