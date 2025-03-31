class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<vector<pair<int,int>>> adjList(n);
            for(auto it:flights)
            {
                adjList[it[0]].push_back({it[1],it[2]});
            }
            queue<pair<int,pair<int,int>>> q;
            vector<int> dist(n,1e9);
            dist[src]=0;
            q.push({0,{src,0}});
            while(!q.empty())
            {
                auto it = q.front();
                q.pop();
                int steps = it.first;
                int node = it.second.first;
                int dis = it.second.second;
                if(steps<=k)
                {
                    for(auto it:adjList[node])
                    {
                        int newdis = it.second;
                        int newnode = it.first;
                        if(newdis + dis < dist[newnode])
                        {
                            dist[newnode] = newdis + dis;
                            q.push({steps+1,{newnode,dist[newnode]}});
                        }
                    }
                }
            } 
            if(dist[dst]==1e9)return -1;
            return dist[dst];
        }
    };