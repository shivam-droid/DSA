class Solution {
    public:
      int minimumMultiplications(vector<int>& arr, int start, int end) {
          // code here
          vector<int> dist(100000,1e9);
          queue<pair<int,int>> q;
          q.push({0,start});
          dist[start]=0;
          int mod = 100000;
          while(!q.empty())
          {
              auto it = q.front();
              q.pop();
              int node = it.second;
              int step = it.first;
              if(node==end)return step;
              for(auto k:arr)
              {
                  int dis = (k*node)%mod;
                  
                  if(dist[dis]>step+1)
                  {
                      dist[dis]=step+1;
                      
                      q.push({step+1,dis});
                  }
              }
          }
          return -1;
          
      }
  };