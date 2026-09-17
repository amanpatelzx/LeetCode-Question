class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> pref(n), suff(n);
        for(int i = 0; i  < n; i++){
            if(i == 0) pref[i] = arr[i];
            else pref[i] = pref[i-1] + arr[i];
        }
        for(int i = n-1; i >= 0; i--){
            if(i == n-1) suff[i] = arr[i];
            else suff[i] = suff[i+1] + arr[i];
        }
        // for(int i = 0; i < n; i++) cout<<pref[i]<<" ";
        // cout<<"\n";
        vector<int> v(n, 1e6);
        for(int i = n-1; i >= 0; i--){
            int last = 0;
            if(i > 0) last = pref[i-1];
            auto it = lower_bound(pref.begin(), pref.end(), last + target);
            if(it != pref.end()){
                int idx = it - pref.begin();
                // cout<<idx<<" ,";
                if(pref[idx] == last + target){
                    if(i == n-1) v[i] = idx - i + 1;
                    else {
                        v[i] = min(v[i+1], idx - i + 1);
                    }
                }
            }
            if(i < n-1) v[i] = min(v[i], v[i+1]);
        }
        // for(int i = 0; i < n; i++) cout<<v[i]<<" ";
        reverse(suff.begin(), suff.end());
        int res = 1e6;
        for(int i = n-1; i >= 0; i--){
            int last = 0;
            if(i > 0) last = suff[i-1];
            auto it = lower_bound(suff.begin(), suff.end(), last + target);
            if(it != suff.end()){
                int idx = it - suff.begin();
                int next = 1e6;
                if(n-i < n) next = v[n-i];
                if(suff[idx] == last + target){
                    res = min(res,  next + idx-i+1);
                }
            }
        }
        return res >= 1e6 ? -1 : res;
    }
};