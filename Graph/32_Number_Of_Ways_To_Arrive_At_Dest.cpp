class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int,int>>> adjList(n);
            for(auto it : roads) {
                adjList[it[0]].push_back({it[1], it[2]});
                adjList[it[1]].push_back({it[0], it[2]});
            }
    
            vector<long long> dist(n, 1e18);
            vector<long long> ways(n, 0);
            int mod = 1e9 + 7;
    
            dist[0] = 0;
            ways[0] = 1;
    
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            pq.push({0, 0});
    
            while(!pq.empty()) {
                auto [dis, node] = pq.top();
                pq.pop();
    
                for(auto [newnode, wt] : adjList[node]) {
                    if(dis + wt < dist[newnode]) {
                        dist[newnode] = dis + wt;
                        ways[newnode] = ways[node];
                        pq.push({dist[newnode], newnode});
                    }
                    else if(dis + wt == dist[newnode]) {
                        ways[newnode] = (ways[newnode] + ways[node]) % mod;
                    }
                }
            }
    
            return ways[n-1] % mod;
        }
    };