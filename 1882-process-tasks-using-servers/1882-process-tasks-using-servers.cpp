class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        set<pair<int,int>> s;
        set<pair<long long,int>> busy;

        for(int i = 0; i < n; i++){
            s.insert({servers[i], i});
        }

        vector<int> ans(m);
        long long curr = 0;

        for(int i = 0; i < m; i++){
            curr = max(curr, 1LL*i);

            while(!busy.empty() && busy.begin()->first <= curr){
                auto [t, id] = *busy.begin();
                busy.erase(busy.begin());

                s.insert({servers[id], id});
            }

            if(s.empty()){
                curr = busy.begin()->first;

                while(!busy.empty() && busy.begin()->first <= curr){
                    auto [t, id] = *busy.begin();
                    busy.erase(busy.begin());

                    s.insert({servers[id], id});
                }
            }
            auto [w, id] = *s.begin();
            s.erase(s.begin());
            ans[i] = id;
            busy.insert({curr + tasks[i], id});
        }
        return ans;
    }
};