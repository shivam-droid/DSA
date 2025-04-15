class Solution {
    public:
        int help (TreeNode* root,int& maxi)
        {
            if(root==NULL)return 0;
            int left = help(root->left,maxi);
            int right = help(root->right,maxi);
            maxi = max(maxi,left+right);
            return 1 + max(left,right);
        }
        int diameterOfBinaryTree(TreeNode* root) {
            int maxi = 0;
            help(root,maxi);
            return maxi;
        }
    };