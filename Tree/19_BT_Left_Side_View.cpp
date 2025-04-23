class Solution {
    public:
        void help(TreeNode* root,int level,vector<int>& ans)
        {
            if(root==NULL)return;
            if(level==ans.size())ans.push_back(root->val);
            if(root->left)help(root->left,level+1,ans);
            if(root->right)help(root->right,level+1,ans);
        }
        vector<int> rightSideView(TreeNode* root) {
            vector<int> ans;
            help(root,0,ans);
            return ans;
        }
    };