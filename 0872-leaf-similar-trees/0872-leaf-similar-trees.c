/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int* ptr;
void recursiveFun(struct TreeNode* root){
     if(root->left==NULL&& root->right==NULL){
        *ptr = root->val;
         ptr++;
        return;
    }
    if(root->left!=NULL)recursiveFun(root->left);
    if(root->right!=NULL)recursiveFun(root->right);
}
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int lfs1[100], lfs2[100];
    for(int i=0;i<100;++i){
        lfs1[i]=-1;lfs2[i]=-1;
    }
    ptr = lfs1;
    recursiveFun(root1);
    ptr = lfs2;
    recursiveFun(root2);
    for(int i=0;i<100;++i){
        if(lfs1[i]!=lfs2[i])return 0;
    }
    return 1;
    
}