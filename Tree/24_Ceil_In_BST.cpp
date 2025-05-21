void help(Node* root,int input,int &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data>=input)
    {
        ans=min(ans,root->data);
        help(root->left,input,ans);
    }
    else
    help(root->right,input,ans);
}


// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL)
        return -1;

    // Your code here
    int ans=1e9;
    help(root,input,ans);
    if(ans==1e9)return -1;
    return ans;
}