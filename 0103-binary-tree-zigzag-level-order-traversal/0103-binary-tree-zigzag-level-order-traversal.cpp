/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while(!q.empty()){
            int k = q.size();
            vector<int> curr;
            while(k--){
                auto tmp = q.front();
                q.pop();
                if(tmp == NULL) continue;
                if(tmp->left != NULL) q.push(tmp->left);
                if(tmp->right != NULL) q.push(tmp->right);

                curr.push_back(tmp->val);
            }
            if(curr.empty()) continue;
            if(res.size() % 2 == 1) reverse(curr.begin(), curr.end());
            res.push_back(curr);
        }
        return res;
    }
};