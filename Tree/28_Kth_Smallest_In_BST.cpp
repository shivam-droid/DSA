class Solution {
public:
    void help(TreeNode* root,int k,int &count,int &ans)
    {
        if(root==NULL)return;
        help(root->left,k,count,ans);
        count++;
        if(count==k)
        {
            ans = root->val;
            return;
        }
        help(root->right,k,count,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        int count=0;
        help(root,k,count,ans);
        return ans;
        
    }
};