class Solution {
    public:
      void dfs(int node,vector<vector<int>>& adj,vector<int>& ans,vector<int>& visList)
      {   
          visList[node]=1;
          ans.push_back(node);
          for(auto it:adj[node])
          {
              if(visList[it]!=1)
              {
                  dfs(it,adj,ans,visList);
              }
          }
          
      }
      // Function to return a list containing the DFS traversal of the graph.
      vector<int> dfsOfGraph(vector<vector<int>>& adj) {
          // Code here
          vector<int> ans;
          vector<int> visList(adj.size(),0);
          dfs(0,adj,ans,visList);
          return ans;
      }
  };