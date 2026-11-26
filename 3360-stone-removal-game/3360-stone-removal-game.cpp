class Solution {
public:
    bool canAliceWin(int n) {
        int turn = 0;
        int target = 10;
        while(1){
            if(n < target){
                if(turn) return true;
                else return false;
            }
            n -= target;
            target--;
            turn = 1 - turn;
        }
        return false;
    }
};