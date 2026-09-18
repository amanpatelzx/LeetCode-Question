class Solution {
public:
    pair<int,int> dp[28][28];
    pair<int,int> f(vector<pair<char,pair<int,int>>> &v, int i, int last, vector<pair<int,int>> &arr){
        if(i >= v.size()) return {0,0};
        if(dp[i][last+1].first != -1 && dp[i][last+1].second != -1) return dp[i][last+1];
        auto A = f(v, i+1, last, arr);
        int idx = v.size();
        pair<int,int> res = A;
        if(last == -1){
            auto B = f(v, i+1, i, arr);
            if(A.first > 1 + B.first){
                res = A;
            }
            else if(A.first < 1 + B.first){
                res = {1 + B.first, 1 + v[i].second.second - v[i].second.first + B.second};
            }
            else if(A.first == 1 + B.first){
                if(A.second < v[i].second.second - v[i].second.first + B.second + 1) res = A;
                else res =  {1 + B.first, v[i].second.second - v[i].second.first + 1 + B.second};
            }
        }
        else if(v[last].second.second < v[i].second.first){
            auto B = f(v, i+1, i, arr);
            if(A.first > 1 + B.first){
                res = A;
            }
            else if(A.first < 1 + B.first){
                res = {1 + B.first, 1 + v[i].second.second - v[i].second.first + B.second};
            }
            else if(A.first == 1 + B.first){
                if(A.second < v[i].second.second - v[i].second.first + B.second + 1) res = A;
                else res =  {1 + B.first, v[i].second.second - v[i].second.first + 1 + B.second};
            }
        }
        return dp[i][last+1] = res;
    }
    void get_ans(string &s,vector<pair<char,pair<int,int>>> &v, int i, int last, pair<int,int> left, vector<string> &res, vector<pair<int,int>> &arr){
        if(left.first == 0 && left.second == 0) return;
        auto A = f(v, i+1, last, arr);
        if(A == left){
            get_ans(s, v, i+1, last, left, res, arr);
            return;
        }
        else{
            string tmp;
            for(int j = v[i].second.first; j <= v[i].second.second; j++) tmp.push_back(s[j]);
            res.push_back(tmp);
            auto B = f(v, i+1, i, arr);
            get_ans(s, v, i+1, i, B, res, arr);
        }
    }
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        map<char,int> mp;
        for(auto &ele : s) mp[ele]++;
        map<char,int> posi;
        map<char, pair<int,int>> range;
        for(int i = 0 ; i < n; i++){
            if(!posi.count(s[i])) posi[s[i]] = i;
        }
        for(int i = 'a'; i <= 'z'; i++){
            char ch = (int)(i);
            if(!mp.count(ch)) continue;
            map<char,int> MP;
            int idx = posi[ch];
            for(int j = idx; j < n; j++){
                if(MP.count(s[j])){
                    MP[s[j]]--;
                    if(MP[s[j]] == 0) MP.erase(s[j]);
                }
                else{
                    MP[s[j]] = mp[s[j]] - 1;
                    if(MP[s[j]] == 0) MP.erase(s[j]);
                }

                if(MP.size() == 0){
                    range[ch] = {idx , j};
                    break;
                }
            }
        }
        vector<pair<char,pair<int,int>>> v;
        for(auto &ele : range){
            v.push_back({ele.first , {ele.second.first , ele.second.second}});
        }
        sort(v.begin(), v.end(), [&](auto &A, auto &B){
            if(A.second.second < B.second.second) return 1;
            else if(A.second.second == B.second.second){
                if(A.second.first < B.second.first) return 1;
                else return 0;
            }
            else return 0;
        });
        // for(int i = 0; i < v.size(); i++){
        //     cout<<v[i].first<<" -> "<<v[i].second.first<<" , "<<v[i].second.second<<"\n";
        // }
        vector<pair<int,int>> arr;
        for(int i = 0; i < v.size(); i++){
            arr.push_back({v[i].second.first, i});
        }
        sort(arr.begin(), arr.end());
        for(int i = 0; i < 28; i++){
            for(int j = 0; j < 28; j++){
                dp[i][j] = {-1, -1};
            }
        }
        auto tmp = f(v, 0, -1, arr);
        // cout<<tmp.first<<" "<<tmp.second<<"\n";
        vector<string> res;
        get_ans(s, v, 0, -1, tmp, res, arr);
        return res;
    }
};