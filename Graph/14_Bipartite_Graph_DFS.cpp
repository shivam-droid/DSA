class Solution {
    public:
        bool dfs(int node,vector<vector<int>>& graph,vector<int>& visArr,int color)
        {
            visArr[node]=color;
            for(auto it:graph[node])
            {
                if(visArr[it]==-1)
                {
                    if(dfs(it,graph,visArr,!color)==false)return false;
                }
                else if(visArr[it]==color)return false;
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
                 if(dfs(i,graph,visArr,0)==false)return false;
                }
            }
            return true;
        }
    };