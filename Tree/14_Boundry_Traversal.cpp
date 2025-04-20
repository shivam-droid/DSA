class Solution{
    public:
        void left(Node* root,vector<int>& res)
        {
            Node* temp = root->left;
            while(temp)
            {
                if(!isLeaf(temp))res.push_back(temp->data);
                if(temp->left)
                temp=temp->left;
                else
                temp=temp->right;
            }
        }
        void leavs(Node* root,vector<int>& res)
        {
            if(root==NULL)return;
            if(isLeaf(root))res.push_back(root->data);
            leavs(root->left,res);
            leavs(root->right,res);
        }
        void right(Node* root,vector<int>& res)
        {
            stack<int> st;
            Node* temp = root->right;
            while(temp)
            {
                if(!isLeaf(temp))st.push(temp->data);
                if(temp->right)temp=temp->right;
                else temp=temp->left;
            }
            while(!st.empty())
            {
                int node = st.top();
                st.pop();
                res.push_back(node);
            }
        }
        bool isLeaf(Node* root)
        {
            
            if(!root->left && !root->right)return true;
            return false;
        }
        vector <int> boundaryTraversal(Node* root){
            //your code goes here
            vector<int> res;
            if(root==NULL)return res;
            if(!isLeaf(root))res.push_back(root->data);
            left(root,res);
            leavs(root,res);
            right(root,res);
            return res;
            
        }
    };