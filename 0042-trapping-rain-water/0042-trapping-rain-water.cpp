class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftLimit = height[0];
        int rightLimit = height.back();
        
        vector<int> pref(n), suff(n);
        for(int i = 0; i < n; i++){
            pref[i] = max(0, leftLimit - height[i]);
            if(height[i] > leftLimit){
                leftLimit = height[i];
            }
        }
        for(int i = n-1; i >= 0; i--){
            suff[i] = max(0, rightLimit - height[i]);
            if(height[i] > rightLimit){
                rightLimit = height[i];
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res += min(pref[i], suff[i]);
        }
        return res;
    }
};