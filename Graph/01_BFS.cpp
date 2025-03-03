class Solution {
    public:
      // Function to return Breadth First Traversal of given graph.
      vector<int> bfsOfGraph(vector<vector<int>> &adj) {
          // Code here
          queue<int> q;
          vector<int> ans;
          vector<int> visList(adj.size(),0);
          q.push(0);
          visList[0]=1;
          while(!q.empty())
          {
              int node = q.front();
              q.pop();
              ans.push_back(node);
              for(auto it:adj[node])
              {
                  if(visList[it]!=1)
                  {
                      q.push(it);
                      visList[it]=1;
                  }
              }
          }
          return ans;
      }
  };