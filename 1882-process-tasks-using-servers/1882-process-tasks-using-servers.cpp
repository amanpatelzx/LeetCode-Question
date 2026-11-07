class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        set<pair<int,int>> s;
        set<pair<long long,int>> S;

        for(int i = 0; i < n; i++){
            s.insert({servers[i], i});
        }

        vector<int> ans(m);
        long long curr = 0;

        for(int i = 0; i < m; i++){
            curr = max(curr, 1LL*i);

            while(!S.empty() && S.begin()->first <= curr){
                auto p = *S.begin();
                S.erase(S.begin());

                s.insert({servers[p.second], p.second});
            }

            if(s.empty()){
                curr = S.begin()->first;

                while(!S.empty() && S.begin()->first <= curr){
                    auto p = *S.begin();
                    S.erase(S.begin());

                    s.insert({servers[p.second], p.second});
                }
            }
            auto p = *s.begin();
            s.erase(s.begin());
            ans[i] = p.second;
            S.insert({curr + tasks[i], p.second});
        }
        return ans;
    }
};