class Solution {
public:
    struct Node{
        int prod;
        int cnt[5];
        Node(){
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int n, k;
    vector<int> nums;
    vector<Node> st;

    Node merge(Node a, Node b){
        Node res;
        res.prod = (a.prod * b.prod) % k;

        for(int i = 0; i < k; i++){
            res.cnt[i] += a.cnt[i];
        }

        for(int i = 0; i < k; i++){
            int r = (a.prod * i) % k;
            res.cnt[r] += b.cnt[i];
        }

        return res;
    }

    void build(int p, int l, int r){
        if(l == r){
            int x = nums[l] % k;
            st[p].prod = x;
            st[p].cnt[x] = 1;
            return;
        }

        int m = (l + r) / 2;

        build(p * 2, l, m);
        build(p * 2 + 1, m + 1, r);

        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, int val){
        if(l == r){
            int x = val % k;

            st[p] = Node();
            st[p].prod = x;
            st[p].cnt[x] = 1;
            return;
        }

        int m = (l + r) / 2;

        if(idx <= m){
            update(p * 2, l, m, idx, val);
        }
        else{
            update(p * 2 + 1, m + 1, r, idx, val);
        }

        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }

    Node query(int p, int l, int r, int qleft, int qright){
        if(qleft <= l && r <= qright){
            return st[p];
        }

        int m = (l + r) / 2;

        if(qright <= m){
            return query(p * 2, l, m, qleft, qright);
        }

        if(qleft > m){
            return query(p * 2 + 1, m + 1, r, qleft, qright);
        }

        Node left = query(p * 2, l, m, qleft, qright);
        Node right = query(p * 2 + 1, m + 1, r, qleft, qright);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries){
        this->nums = nums;
        this->k = k;
        this->n = nums.size();

        st.resize(4 * n + 5);
        build(1, 0, n - 1);

        vector<int> ans;

        for(auto &q : queries){
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, idx, val);
            Node res = query(1, 0, n - 1, start, n - 1);
            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};