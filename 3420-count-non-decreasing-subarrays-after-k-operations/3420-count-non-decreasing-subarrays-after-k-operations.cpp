class Solution {
public:
    #define ll long long
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        ll n = nums.size();

        vector<ll> v(n , n); 
        stack<ll> st;
        
        for(ll i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                v[i] = st.top();
            }
            st.push(i);
        }

        ll res = 0;
        ll diff = 0;      
        ll maxi = nums[0]; 
        ll j = 0;

        for(ll i = 0; i < n; i++){
            if(j < i){  
                j = i;
                diff = 0;
                maxi = nums[i];
            }

            for(; j < n; j++){
                ll maxi1 = max(maxi, 1LL*nums[j]);
                if(diff + (maxi1 - nums[j]) > k){ 
                    break;
                }
                maxi = maxi1;
                diff += maxi - nums[j];
            }
            
            res += (j - i); 

            for(ll tt = i+1; tt < j && nums[tt] < nums[i]; tt = v[tt]){
                ll h = nums[i] - nums[tt];
                ll base = min(j, v[tt]);
                diff -= (h * (base - tt));
                if(base == j) maxi = nums[tt]; 
            }
            if(j == i+1 && i+1 < n) maxi = nums[i+1];
        }
        return res;
    }
};