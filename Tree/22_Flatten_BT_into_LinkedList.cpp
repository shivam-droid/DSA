class Solution {
public:
    TreeNode* temp = NULL;
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        flatten(root->right);
        flatten(root->left);
        root->right=temp;
        root->left = NULL;
        temp=root;

    }
};