class Solution {
public:
    bool help(TreeNode* root,long left, long right)
    {
        if(root==NULL)return true;
        if(root->val>=right || root->val<=left)return false;
        return help(root->left,left,root->val) && help(root->right,root->val,right);
    }
    bool isValidBST(TreeNode* root) {
        return help(root,LONG_MIN,LONG_MAX);
    }
};