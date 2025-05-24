class Solution {
public:
    TreeNode* left(TreeNode* root)
        {
            if(root->right==NULL)return root;
            return left(root->right);
        }

    TreeNode* help(TreeNode* root)
        {
            if(root->left==NULL)return root->right;
            else if(root->right==NULL)return root->left;
            TreeNode* rightChild = root->right;
            TreeNode* leftlast = left(root->left);
            leftlast->right = rightChild;
            return root->left;
        }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return root;
        if(root->val==key) return help(root);
        TreeNode* dummy = root;
        while(root)
        {
            if(root->val>key)
            {
                if(root->left!=NULL && root->left->val==key)
                {
                    root->left = help(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if(root->right!=NULL && root->right->val==key)
                {
                    root->right = help(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }

        
        

        return dummy;

    }
};