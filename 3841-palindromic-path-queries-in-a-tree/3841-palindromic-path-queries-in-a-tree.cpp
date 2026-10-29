
class SegmentTree {
    int n;
    vector<int> tree;

    void build(vector<int> &arr, int node, int l, int r) {
        if(l == r) {
            tree[node] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(arr, 2 * node, l, mid);
        build(arr, 2 * node + 1, mid + 1, r);

        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    void update(int node, int l, int r, int idx, int val) {
        if(l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if(idx <= mid) update(2 * node, l, mid, idx, val);
        else update(2 * node + 1, mid + 1, r, idx, val);

        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return tree[node];

        int mid = (l + r) / 2;

        return query(2 * node, l, mid, ql, qr) ^
               query(2 * node + 1, mid + 1, r, ql, qr);
    }

public:
    SegmentTree(vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    int LOG, timer;
    vector<vector<int>> g, up;
    vector<int> depth, in, out, mask, euler;

    void dfs(int u, int p, int d) {
        depth[u] = d;
        up[u][0] = p;

        for(int k = 1; k < LOG; k++) {
            up[u][k] = up[up[u][k - 1]][k - 1];
        }

        in[u] = timer;
        euler[timer++] = mask[u];

        for(int v : g[u]) {
            if(v == p) continue;
            dfs(v, u, d + 1);
        }

        out[u] = timer;
        euler[timer++] = mask[u];
    }

    int lca(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for(int k = 0; k < LOG; k++) {
            if((diff >> k) & 1) u = up[u][k];
        }

        if(u == v) return u;

        for(int k = LOG - 1; k >= 0; k--) {
            if(up[u][k] != up[v][k]) {
                u = up[u][k];
                v = up[v][k];
            }
        }

        return up[u][0];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        LOG = 17;

        g.assign(n, vector<int>());

        for(auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        mask.resize(n);

        for(int i = 0; i < n; i++) {
            mask[i] = 1 << (s[i] - 'a');
        }

        up.assign(n, vector<int>(LOG, 0));
        depth.resize(n);
        in.resize(n);
        out.resize(n);
        euler.resize(2 * n);
        timer = 0;

        dfs(0, 0, 0);

        SegmentTree seg(euler);
        vector<bool> ans;

        for(string &q : queries) {
            string op;
            stringstream ss(q);
            ss >> op;

            if(op == "update") {
                int u;
                char c;
                ss >> u >> c;

                int val = 1 << (c - 'a');
                mask[u] = val;

                seg.update(in[u], val);
                seg.update(out[u], val);
            } else {
                int u, v;
                ss >> u >> v;

                int w = lca(u, v);

                int x = seg.query(0, in[u]);
                int y = seg.query(0, in[v]);

                int curr = x ^ y ^ mask[w];

                ans.push_back((curr & (curr - 1)) == 0);
            }
        }

        return ans;
    }
};
