class Solution {
public:
    int maxLen(TreeNode* root)
    {
        if(root==NULL)return 0;
        int left = maxLen(root->left);
        if(left==-1)return -1;
        int right = maxLen(root->right);
        if(right==-1)return -1;
        if(abs(left-right)>1)return -1;
        return 1+max(left,right);

    }
    bool isBalanced(TreeNode* root) {
        return maxLen(root)!=-1;
    }
};