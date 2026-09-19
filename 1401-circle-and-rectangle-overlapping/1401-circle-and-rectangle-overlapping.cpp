class Solution {
public:
    //Bhai , kisi point se line pe perpendicular ka distance kya hota hai -> d
    //eg. if ax + by + c = 0, points (x1,y1) => d = abs(ax1 + by1 + c) / sqrt(a^2 + b^2); 
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(xCenter >= x1 && xCenter <= x2 && yCenter >= y1 && yCenter <= y2 ) return 1;

        //center will be outsie of the rectange ->
        //lets take a,b,c,d end points of rectange
        //a = {x1,y1}, b = {x2,y1}, c = {x2, y2}, d = {x1, y2};
        vector<pair<double,pair<int,int>>> arr;
        double d1 = sqrt((xCenter - x1)*(xCenter - x1) + (yCenter - y1)*(yCenter - y1));
        arr.push_back({d1, {x1, y1}});
        double d2 = sqrt((xCenter - x1)*(xCenter - x1) + (yCenter - y2)*(yCenter - y2));
        arr.push_back({d2, {x1, y2}});
        double d3 = sqrt((xCenter - x2)*(xCenter - x2) + (yCenter - y2)*(yCenter - y2));
        arr.push_back({d3, {x2, y2}});
        double d4 = sqrt((xCenter - x2)*(xCenter - x2) + (yCenter - y1)*(yCenter - y1));
        arr.push_back({d4, {x2, y1}});

        sort(arr.begin(), arr.end());
        if(arr[0].first <= radius) return true;
        //(y - y1)/(x-x1) = (y2 - y1)/(x2 - x1);
        //(y-y1)*(x2 - x1) = (y2 - y1)*(x-x1);
        // (x2 - x1)*y - (y2-y1)*x = y1(x2 - x1) - x1(y2-y1);
        //A = (y2-y1), B = (x1 - x2), C = x1(y2 - y1) - y1(x2 - x1); 
        //C = x1*y2 - x1*y1 - y1*x2 + y1*x1 => c = x1*y2 - y1*x2;
        int X1 = arr[0].second.first;
        int Y1 = arr[0].second.second;

        for(int i = 1; i < 4; i++){
            int X2 = arr[i].second.first;
            int Y2 = arr[i].second.second;
            
            //cout<<X1<<" "<<X2<<" "<<Y1<<" "<<Y2<<" ";
            if(X1 == X2 || Y1 == Y2){
                double A = Y2 - Y1;
                double B = X1 - X2;
                double C = X2*Y1 - X1*Y2;

                double D = abs(A*xCenter + B*yCenter + C) / sqrt(A*A + B*B);
                bool ok = false;
                if(X1 == X2){ 
                    if (yCenter >= min(Y1, Y2) && yCenter <= max(Y1, Y2)) ok = true;
                } 
                else if(Y1 == Y2){ 
                    if(xCenter >= min(X1, X2) && xCenter <= max(X1, X2)) ok = true;
                }
                if(ok && D <= radius) return 1;
            }
        }
        return false;
    }
};