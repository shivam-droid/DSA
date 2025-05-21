class Solution {

  public:
    void help(Node* root,int x,int &ans)
    {
        if(root==NULL)return;
        if(root->data<=x)
        {
            ans=max(ans,root->data);
            help(root->right,x,ans);
        }
        else
        help(root->left,x,ans);
    }
    int floor(Node* root, int x) {
        // Code here
        if(root==NULL)return -1;
        int ans=-1e9;
        help(root,x,ans);
        if(ans==-1e9)return -1;
        return ans;
        
    }
};

// Floor means the greatest element which is less than or equal to x
// Ceil means the smallest element which is greater than or equal to x