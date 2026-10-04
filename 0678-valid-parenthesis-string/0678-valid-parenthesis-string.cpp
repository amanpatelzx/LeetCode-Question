class Solution {
public:
    bool checkValidString(string s) {
        int left = 0;
        int star = 0;
        
        for(auto &ch : s){
            if(ch == '(') left++;
            else if(ch == '*') star++;
            else{
                if(left > 0) left--;
                else if(star > 0) star--;
                else return false; 
            }
        }
        
        int right = 0;
        star = 0;

        for(int i = s.size() - 1; i >= 0; i--){
            char ch = s[i];
            if(ch == ')') right++;
            else if(ch == '*') star++;
            else{
                if(right > 0) right--;
                else if(star > 0) star--;
                else return false;
            }
        }
        return true;
    }
};