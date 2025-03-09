class Solution {
    public:
      bool dfs(int i,vector<vector<int>>& adj,vector<int>& visArr,int parent)
      {
          visArr[i]=1;
          for(auto it:adj[i])
          {
              if(visArr[it]!=1)
              {
                  if(dfs(it,adj,visArr,i)==true)return true;
              }
              else
              {
                  if(it!=parent)return true;
              }
          }
          return false;
          
      }
      
      // Function to detect cycle in an undirected graph.
      bool isCycle(vector<vector<int>>& adj) {
          // Code here
          int n = adj.size();
          vector<int> visArr(n,0);
          for(int i=0;i<n;i++)
          {
              if(visArr[i]!=1)
              {
                  if(dfs(i,adj,visArr,-1)==true)return true;
              }
          }
          return false;
          
          
      }
  };