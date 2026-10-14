class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int cnt = (sum + 8) / 9;
        if(cnt > num) return "";
        string res;
        while(num--){
            if(sum >= 9){
                res.push_back('9');
                sum -= 9;
            }
            else{
                res.push_back(char('0' + sum));
                sum = 0;
            }
        }
        return res;
    }
};