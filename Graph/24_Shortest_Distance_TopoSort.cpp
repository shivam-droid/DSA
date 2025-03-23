class Solution {
    public:
      void toposort(int node,vector<vector<pair<int,int>>>& adjList,vector<int>& vis,
      stack<int>& st)
      {
          vis[node]=1;
          for(auto it:adjList[node])
          {
              if(vis[it.first]!=1)
              {
                  toposort(it.first,adjList,vis,st);
              }
          }
          st.push(node);
      }
      vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
          // code here
          vector<vector<pair<int,int>>> adjList(V);
          for(int i=0;i<E;i++)
          {
              int u = edges[i][0];
              int v = edges[i][1];
              int wt = edges[i][2];
              adjList[u].push_back({v,wt});
          }
          vector<int> vis(V,0);
          stack<int> st;
          for(int i=0;i<V;i++)
          {
              if(vis[i]!=1)
              {
                  toposort(i,adjList,vis,st);
              }
          }
          vector<int> dis(V,1e9);
          dis[0]=0;
          while(!st.empty())
          {
              int node = st.top();
              st.pop();
              for(auto it:adjList[node])
              {
                  if((dis[node]+it.second)<dis[it.first])
                  {
                      dis[it.first]=dis[node]+it.second;
                  }
              }
          }
          for(int i=0;i<V;i++)
          {
              if(dis[i]==1e9) 
              dis[i]=-1;
          }
          return dis;
      }
  };