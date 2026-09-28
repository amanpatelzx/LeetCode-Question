class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n = s.size();
        int depth = 0;
        int curr = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') curr++;
            else curr--;
            depth = max(depth , curr);
        }
        int req = depth/2;

        stack<int> st;
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++){
            if(s[i] == '(') st.push(i);
            else{
                if(st.size() <= req){
                    res[i] = 1;
                    res[st.top()] = 1;
                    st.pop();
                }
                else{
                    st.pop();
                }
            }
        }
        return res;
    }
};