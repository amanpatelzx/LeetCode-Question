class Solution {
public:
    int n, m;
    int dp[100004];
    vector<int> arr1, arr2, tar1, tar2;

    int f(vector<vector<int>> &arr, vector<vector<int>> &target, int i){
        int a = arr[i][0], b = arr[i][1];
        int idx4 = upper_bound(tar2.begin(), tar2.end(), b) - tar2.begin();
        if(idx4 >= m) return 0;
        if(dp[i] != -1) return dp[i];

        int idx = upper_bound(arr2.begin(), arr2.end(), b) - arr2.begin();
        int idx1 = lower_bound(arr2.begin(), arr2.end(), target[idx4][0]) - arr2.begin();
        int idx2 = max(idx, idx1);
        if(idx2 == n) return 1e6;

        int ans = 1e7;
        for(int j = idx2; j < n; j++){
            if(arr[j][0] > max(b, target[idx4][0])) break;
            else{
                ans = min(ans , 1 + f(arr, target, j));
            }
        }
        return dp[i] = ans;
    }

    int minSelection(vector<vector<int>>& nums, vector<vector<int>>& target) {
        arr1.clear(); arr2.clear(); tar1.clear(); tar2.clear();
        n = nums.size();
        m = target.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> arr;
        int a = nums[0][0], b = nums[0][1];
        for(int i = 1; i < n; i++){
            int A = nums[i][0];
            int B = nums[i][1];
            if(A == a){
                b = max(b, B);
            }
            else if(b >= B){
                continue;
            }
            else{
                arr.push_back({a,b});
                a = A;
                b = B;
            }
        }
        arr.push_back({a,b});
        n = arr.size();
        for(int i = 0; i < n; i++){
            arr1.push_back(arr[i][0]);
            arr2.push_back(arr[i][1]);
        }

        sort(target.begin(), target.end());
        vector<vector<int>> tar;
        a = target[0][0], b = target[0][1];
        for(int i = 1; i < m; i++){
            int A = target[i][0];
            int B = target[i][1];
            if(b >= A){
                b = max(b, B);
            }
            else{
                tar.push_back({a,b});
                a = A;
                b = B;
            }
        }
        tar.push_back({a,b});
        target = tar;
        m = target.size();
        for(int i = 0; i < m; i++){
            tar1.push_back(target[i][0]);
            tar2.push_back(target[i][1]);
        }

        memset(dp, -1, sizeof(dp));
        int ans = 1e7;
        int idx = lower_bound(arr2.begin(), arr2.end(), target[0][0]) - arr2.begin();
        for(int i = idx; i < n; i++){
            if(arr[i][0] > target[0][0]) break;
            else{
                ans = min(ans , 1 + f(arr, target, i));
            }
        }
        if(ans >= 1e5) return -1;
        return ans;
    }
};