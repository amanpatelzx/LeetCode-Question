#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef __int128_t lll;
#define UM unordered_map
#define US unordered_set
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define For(i,a,b) for (int i = a; i < b; i++)


class Solution {
public:
    #define ll long long
    typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
    
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        int n = nums.size();
        vector<ll> pref(n);
        for(int i = 0; i < n; i++){
            if(i == 0) pref[i] = nums[i];
            else pref[i] = pref[i-1] + (ll)nums[i];
        }
        
        ordered_set s;
        for(int i = 0; i < n; i++){
            s.insert({pref[i], i});
        }
        
        ll res = 0;
        for(int i = 0; i < n; i++){
            ll last = 0;
            if(i > 0) last = pref[i-1];
            
            if(i != 0){
                s.erase({last, i-1}); 
            }

            ll left = s.order_of_key({last + goal - k, n + 1});
            ll right = s.order_of_key({last + goal + k, -1});
            ll middle = max((ll)0, right - left);
    
            res += s.size() - middle;
        }
        return res;
    }
};