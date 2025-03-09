class Solution {
    public:
        bool bfs(int node,vector<vector<int>>& graph,vector<int>& visArr)
        {
            visArr[node]=0;
            queue<int> q;
            q.push(node);
            while(!q.empty())
            {
                int adjnode = q.front();
                q.pop();
                for(auto it:graph[adjnode])
                {
                    if(visArr[it]==-1)
                    {
                        visArr[it]=!visArr[adjnode];
                        q.push(it);
                    }
                    else if(visArr[it]==visArr[adjnode])return false;
                }
            }
            return true;
        }
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> visArr(n,-1);
            for(int i=0;i<n;i++)
            {  
                if(visArr[i]==-1)
                {
                 if(bfs(i,graph,visArr)==false)return false;
                }
            }
            return true;
        }
    };