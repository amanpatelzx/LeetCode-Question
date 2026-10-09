class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int res = 0;
        int cnt = 0;
        int i = 0;
        while(i < n){
            if(s[i] == '(') cnt++;
            else{
                if(cnt > 0){
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
                    cnt--;
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
        res += 2*cnt;
        return res;
    }
};