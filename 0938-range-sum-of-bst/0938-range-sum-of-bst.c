/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum=0;
void recursiveFun(struct TreeNode* root, int low, int high){
    if(root->left==NULL&& root->right==NULL){
        if(root->val >= low && root->val <= high)sum+=root->val;
        return;
    }
    if(root->val >= low && root->val <= high)sum+=root->val;
    if(root->left!=NULL)recursiveFun(root->left,low,high);
    if(root->right!=NULL)recursiveFun(root->right,low,high);
}
int rangeSumBST(struct TreeNode* root, int low, int high) {
    sum=0;
    recursiveFun(root,low,high);
    return sum;
}