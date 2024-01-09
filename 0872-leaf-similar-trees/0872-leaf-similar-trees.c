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
         // printf("%d ",*ptr);
         ptr++;
        return;
    }
    if(root->left!=NULL)recursiveFun(root->left);
    if(root->right!=NULL)recursiveFun(root->right);
}
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int lfs1[200], lfs2[200];
    for(int i=0;i<200;++i){
        lfs1[i]=-1;
        lfs2[i]=-1;
    }
    ptr = lfs1;
    recursiveFun(root1);
    ptr = lfs2;
    // printf("\n");
    recursiveFun(root2);
   //  printf("\n");
   // for(int i=0;i<200;++i){
   //       printf("%d ",lfs1[i]);
   //       printf("%d ",lfs2[i]);
   //  }
    // printf("\n");
    
    for(int i=0;i<200;++i){
         printf("%d ",lfs1[i]);
         printf("%d ",lfs2[i]);
        if(lfs1[i]!=lfs2[i])return 0;
    }
    return 1;
    
}