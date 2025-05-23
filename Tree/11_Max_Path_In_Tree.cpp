class Solution {
    public:
        int help(TreeNode* root,int& maxi)
        {
            if(root==NULL)return 0;
            int left = max(0,help(root->left,maxi));
            int right = max(0,help(root->right,maxi));
            maxi = max(maxi,root->val + (left+right));
            return root->val + max(left,right);
        }
        int maxPathSum(TreeNode* root) {
            int maxi = INT_MIN;
            help(root,maxi);
            return maxi;
        }
    };