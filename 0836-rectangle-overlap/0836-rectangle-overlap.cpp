class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], x2 = rec1[2], y1 = rec1[1], y2 = rec1[3];
        int a1 = rec2[0], a2 = rec2[2], b1 = rec2[1], b2 = rec2[3];

        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        if(a1 > a2) swap(a1, a2);
        if(b1 > b2) swap(b1, b2);

        if(x1 <= a1){
            if(x2 > a1){
                if(y1 < b1){
                    if(y2 > b1) return 1;
                }
                else{
                    if(b2 > y1) return 1;
                }
            }
        }
        if(a1 <= x1){
            if(a2 > x1){
                if(b1 < y1){
                    if(b2 > y1) return 1;
                }
                else{
                    if(y2 > b1) return 1;
                }
            }
        }
        
        return 0;
    }
};