class Solution {
public:
    pair<bool,pair<int,int>> check(vector<int>& nums, int start, int end){
        int miniIdx = start;
        int maxIdx = start;
        int k = end - start;
        for(int i = start; i <= end; i++){
            if(nums[i] < nums[miniIdx]) miniIdx = i;
            if(nums[i] > nums[maxIdx]) maxIdx = i;
        }
        for(int i = maxIdx; i <= maxIdx+k; i++){
            int idx = i;
            if(idx > end) idx = start + i - end -1;
            if(nums[idx] == nums[miniIdx]){
                miniIdx = idx;
                break;
            }
        }
        int last = -1;
        for(int i = miniIdx; i <= miniIdx + k; i++){
            int idx = i;
            if(i > end){
                idx = start + i - end-1;
            }
            if(nums[idx] < last) return {false, {-1,-1}};
            else{
                last = nums[idx];
            }
        }
        return { true, { nums[miniIdx], nums[maxIdx]}};
    }
    bool f(vector<int> &nums, int k){
        int n = nums.size();
        int lastMax = 0;
        for(int i = 0; i <= n-k; i += k){
            auto p = check(nums, i, i+k-1);
            if(p.first == false) return false;
            else{
                if(p.second.first < lastMax) return false;
                else{
                    lastMax = p.second.second;
                }
            }
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        //auto p = check(nums, 0, n-1);
        //cout<<p.first<<" -> "<<p.second.first<<" ,"<<p.second.second<<"\n";
        int res = 0;
        for(int i = 1; i*i <= n; i++){
            if(n % i == 0){
                if(f(nums, i)) res += i;
                if(i*i != n){
                    int tt = n/i;
                    if(f(nums, tt)) res += tt;
                }
            }
        }
        return res;
    }
};