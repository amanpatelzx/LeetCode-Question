    #define ll long long 
    set<ll> s;
    void f(string &tt){
        if(tt.size() > 5) return;
        // cout<<tt<<" -> ";
        string t1 = tt;
        reverse(t1.begin(), t1.end());
        if(tt != ""){
            ll yy = stoll(tt + t1);
            s.insert(yy);
        }
        for(int i = 0; i < 10; i++){
            if(tt == "0") continue;
            string tmp = tt + char((int)('0') + i) + t1;
            // cout<<tmp<<"  ,";
            ll val = stoll(tmp);
            s.insert(val);
            tt += char((int)('0') + i);
            f(tt);
            tt.pop_back();
        }
        return;
        // cout<<"\n";
    }
    vector<ll> even, odd;
    int cnt = 0;
    void f2(){
        if(cnt == 0){
            string tt;
            f(tt);
            s.insert(0);
            for(auto &ele : s){
                if(ele % 2 == 0) even.push_back(ele);
                else odd.push_back(ele);
            }
            cnt++;
        }
        return;
    }


class Solution {
public:
    
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        f2();
        ll res = 0;
        // cout<<even.size()<<" "<<odd.size()<<"\n";
        // for(auto &ele : even) cout<<ele<<' ';
        // cout<<"\n";
        // for(auto &ele : odd) cout<<ele<<' ';
        // cout<<"\n";
        for(int i = 0; i < n; i++){
            ll curr = nums[i];
            if(curr % 2 == 0){
                auto it = lower_bound(even.begin(), even.end(), curr);
                int idx = it - even.begin();
                ll val = even[idx];
                ll prev = 0;
                prev = even[idx-1];

                ll ans = (val - curr) / 2;
                ans = min(ans , (ll)((curr - prev)/ 2));
                res += ans;
            }
            else {
                auto it = lower_bound(odd.begin(), odd.end(), curr);
                int idx = it - odd.begin();
                ll val = odd[idx];
                ll prev = 0;
                if(idx > 0) prev = odd[idx-1];
                ll ans = (val - curr) / 2;
                if(curr > 1) ans = min(ans , (ll)((curr - prev)/ 2));
                res += ans;
            }

        }
        return res;
    }
};