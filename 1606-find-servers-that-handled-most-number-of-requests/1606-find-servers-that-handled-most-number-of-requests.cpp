#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> count(k);
        priority_queue<pair<int,int>> pq;
        ordered_set s;
        for(int i = 0; i < k; i++){
            s.insert(i);
        }
        for(int i = 0; i < n; i++){
            int val = i % k;

            while(!pq.empty() && -1*pq.top().first <= arrival[i]){
                auto p = pq.top();
                pq.pop();
                s.insert(p.second);
            }

            if(s.size() == 0) continue;
            auto it = s.lower_bound(val);
            int idx;
            if(it != s.end()){
                idx = *it;
            }
            else{
                it = s.lower_bound(0);
            }
            idx = *it;
            s.erase(it);
            pq.push({-1*(arrival[i] + load[i]), idx});
            count[idx]++;
        }
        int maxi = *max_element(count.begin(), count.end());
        vector<int> res;
        for(int i = 0; i < k; i++){
            if(count[i] == maxi) res.push_back(i);
        }
        sort(res.begin(), res.end());
        return res;
    }
};