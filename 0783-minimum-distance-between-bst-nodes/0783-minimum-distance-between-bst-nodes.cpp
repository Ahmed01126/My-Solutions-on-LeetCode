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
    set<int>s;
    void dfs(TreeNode *root) {
        if (root == nullptr)return;
        s.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int minDiffInBST(TreeNode *root) {
        dfs(root);
        int mn=1e9;
        int x = 1e8;
        for(auto i : s){
            if(x==1e8){
                x=i;
                continue;
            } 
            mn=min(abs(x-i),mn);
            x=i;
        }

        return mn;
    }
};