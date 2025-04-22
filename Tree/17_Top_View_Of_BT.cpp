class Solution {
    public:
      // Function to return a list of nodes visible from the top view
      // from left to right in Binary Tree.
      vector<int> topView(Node *root) {
          // code here
          map<int,int> mpp;
          queue<pair<Node*,int>> q;
          q.push({root,0});
          while(!q.empty())
          {
              auto p = q.front();
              q.pop();
              Node* node = p.first;
              int line = p.second;
              if(mpp.find(line)==mpp.end()) mpp[line] = node->data;
              if(node->left)q.push({node->left,line-1});
              if(node->right)q.push({node->right,line+1});
          }
          vector<int> ans;
          for(auto a:mpp)
          {
              ans.push_back(a.second);
          }
          return ans;
      }
  };