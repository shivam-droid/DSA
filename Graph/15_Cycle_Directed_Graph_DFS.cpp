class Solution {
    public:
      bool dfs(int node,vector<vector<int>> &adj,vector<int>& visArr,vector<int>&pathVis)
      {
          visArr[node]=1;
          pathVis[node]=1;
          for(auto it:adj[node])
          {
              if(visArr[it]!=1)
              {
                  if(dfs(it,adj,visArr,pathVis)==true)return true;
              }
              else if(pathVis[it]==1)return true;
          }
          pathVis[node]=0;
          return false;
      }
      // Function to detect cycle in a directed graph.
      bool isCyclic(vector<vector<int>> &adj) {
          // code here
          int n = adj.size();
          vector<int> visArr(n,0);
          vector<int> pathVis(n,0);
          for(int i=0;i<n;i++)
          {
              if(visArr[i]!=1)
              {
                  if(dfs(i,adj,visArr,pathVis)==true)return true;
              }
          }
          return false;
      }
  };