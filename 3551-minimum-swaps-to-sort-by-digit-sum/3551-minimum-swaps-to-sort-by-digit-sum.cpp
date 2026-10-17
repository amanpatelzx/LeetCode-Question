class Solution {
public:
    int digit_sum(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(nums.begin(), nums.end(), [&](auto &a, auto &b){
            int A = digit_sum(a);
            int B = digit_sum(b);
            if(A < B) return true;
            if(A == B){
                if(a < b) return true;
                else return false;
            }
            else return false;
        });
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]] = i;
        }
        int res = 0;
    
        for(int i = 0; i < n; i++){
            if(arr[i] != nums[i]){
                res++;
                int j = mp[nums[i]];
                swap(arr[i], arr[j]);
                mp[arr[j]] = j;
                mp[arr[i]] = i;
            }
        }
        return res;
    }
};