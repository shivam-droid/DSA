class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int> mpp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int line = p.second;
            mpp[line]=node->data;
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