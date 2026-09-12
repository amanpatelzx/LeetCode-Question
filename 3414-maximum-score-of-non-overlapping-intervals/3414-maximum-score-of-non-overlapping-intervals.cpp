class Solution {
public:
    #define ll long long
    vector<int> v;
    ll dp[50003][8];
    ll f(vector<vector<int>> &arr, int curr, int cnt){
        int n = arr.size();
        if(curr >= n || cnt == 0) return 0;
        if(dp[curr][cnt+2] != -1) return dp[curr][cnt+2];
        ll res = 0;
        res = max(res, f(arr, curr+1, cnt));

        auto it = upper_bound(v.begin(), v.end(), arr[curr][1]);
        int idx = it - v.begin();
        res = max(res , arr[curr][3] + f(arr, idx, cnt-1));

        return dp[curr][cnt+2] = res;
    }
    set<vector<int>> allPath;
    void get_path(vector<vector<int>> &arr ,int curr , vector<int> &path, ll left, int cnt){
        // if(!allPath.empty())
        if(left == 0){
            vector<int> tmp = path;
            sort(tmp.begin(), tmp.end());
            allPath.insert(tmp);
            return;
        }
        if(curr >= arr.size() || cnt == 0) return;
        auto it = upper_bound(v.begin(), v.end(), arr[curr][1]);
        int idx = it - v.begin();
        ll take = arr[curr][3] + f(arr, idx, cnt-1);
        ll notTake = f(arr, curr+1, cnt);
        if(take == left){
            path.push_back(arr[curr][2]);
            get_path(arr, idx, path, left - arr[curr][3], cnt-1);
            path.pop_back();
        }
        if(notTake == left){
            get_path(arr, curr+1, path, left, cnt);
        }
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> arr;
        set<vector<int>> s;
        for(int i = 0; i < n; i++){
            if(!s.count({intervals[i][0] ,intervals[i][1] ,intervals[i][2]})){
                arr.push_back({intervals[i][0] , intervals[i][1], i, intervals[i][2]});
                s.insert({intervals[i][0] ,intervals[i][1] ,intervals[i][2]});
            }

        }
        sort(arr.begin(), arr.end());
        memset(dp, -1, sizeof(dp));
        // for(int i = 0; i < n; i++){
        //     cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<" "<<arr[i][3]<<"\n";
        // }
        for(int i = 0; i < arr.size(); i++) v.push_back(arr[i][0]);
        ll res = f(arr, 0 , 4);
        // cout<<"Maximum ans is - > "<<res<<"\n";
        vector<int> path;
        get_path(arr, 0, path, res, 4);
        // sort(allPath.begin(), allPath.end());
        // for(auto &ele : allPath){
        //     for(auto &it : ele) cout<<it<<" ";
        //     cout<<"\n";
        // }
        return *(allPath.begin());
    }
};