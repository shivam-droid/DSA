class Solution {
    public:
      void help(Node* root,vector<int>& temp,vector<vector<int>>& ans)
      {
          if(root==NULL)
          {
              
              return;
          }
          temp.push_back(root->data);
          if(root->left==NULL && root->right==NULL)
          {
              ans.push_back(temp);
          }
          else
          {
              help(root->left,temp,ans);
              help(root->right,temp,ans);
          }
          temp.pop_back();
      }
      vector<vector<int>> Paths(Node* root) {
          // code here
          vector<vector<int>> ans;
          vector<int> temp;
          help(root,temp,ans);
          return ans;
      }
  };