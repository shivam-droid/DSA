class Solution {
    public:
      bool bfs(int i,vector<vector<int>>& adj,vector<int>& visArr)
      {
          queue<pair<int,int>> q;
          visArr[i]=1;
          q.push({i,-1});
          while(!q.empty())
          {
              auto it = q.front();
              q.pop();
              int node = it.first;
              int parent = it.second;
              for(auto it:adj[node])
              {
                  if(visArr[it]!=1)
                  {
                      q.push({it,node});
                      visArr[it]=1;
                  }
                  else
                  {
                      if(parent!=it)return true;
                  }
              }
          }
          return false;
      }
      // Function to detect cycle in an undirected graph.
      bool isCycle(vector<vector<int>>& adj) {
          // Code here
          
          vector<int> visArr(adj.size());
          int n = adj.size();
          for(int i=0;i<n;i++)
          {
              if(visArr[i]!=1)
              {
                  if(bfs(i,adj,visArr)==true)return true;
              }
          }
          return false;
          
      }
  };