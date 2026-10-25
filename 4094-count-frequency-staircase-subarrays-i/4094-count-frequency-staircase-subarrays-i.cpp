class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            map<int,int> mp;
            vector<int> v;
            for(int j = i; j < n; j++){
                if(!mp.count(nums[j])){
                    v.push_back(nums[j]);
                }
                mp[nums[j]]++;
                int curr = 1;
                for(auto &ele : v){
                    if(mp[ele] == curr){
                        curr++;
                    }
                    else{
                        curr = -1;
                        break;
                    }
                }
                if(curr != -1) res++;
            }
        }
        return res;
    }
};