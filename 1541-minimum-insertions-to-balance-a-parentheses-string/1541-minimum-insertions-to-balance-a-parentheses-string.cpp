class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int res = 0;
        stack<int> st;
        int i = 0;
        while(i < n){
            if(s[i] == '(') st.push(0);
            else{
                if(!st.empty()){
                    if(i+1 < n){
                        if(s[i+1] == ')'){
                            i++;
                        }
                        else{
                            res += 1;
                        }
                    }
                    else{
                        res += 1;
                    }
                    st.pop();
                }
                else{
                    if(i+1 < n){
                        if(s[i+1] == ')'){
                            i++;
                            res++;
                        }
                        else{
                            res += 2;
                        }
                    }
                    else{
                        res += 2;
                    }
                }
            }
            i++;
        }
        int m = st.size();
        res += 2*m;
        return res;
    }
};