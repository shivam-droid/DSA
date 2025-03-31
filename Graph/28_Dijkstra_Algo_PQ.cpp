class Solution {
    public:
      // Function to find the shortest distance of all the vertices
      // from the source vertex src.
      vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
          // Code here
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
          q.push({0,src});
          vector<int> dist(adj.size(),1e9);
          dist[src]=0;
          while(!q.empty())
          {
              auto it = q.top();
              q.pop();
              int srcDis = it.first;
              int srcNode = it.second;
              for(auto node:adj[srcNode])
              {
                  int totalDis = srcDis + node.second;
                  if(dist[node.first]>totalDis)
                  {
                      dist[node.first]=totalDis;
                      q.push({totalDis,node.first});
                  }
              }
          }
          return dist;
      }
  };