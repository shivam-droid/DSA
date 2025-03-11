class Solution {
    public:
        bool dfs(int node,vector<vector<int>>& graph,vector<int>& visArr,vector<int>& pathVis)
        {
            visArr[node]=1;
            pathVis[node]=1;
            for(auto it:graph[node])
            {
                if(visArr[it]!=1)
                {
                    if(dfs(it,graph,visArr,pathVis)==true)return true;
                }
                else if(pathVis[it]==1)return true;
            }
            pathVis[node]=0;
            return false;
        }
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> visArr(n,0);
            vector<int> pathVis(n,0);
            for(int i=0;i<n;i++)
            {
                if(visArr[i]!=1)
                {
                    dfs(i,graph,visArr,pathVis);
                }
            }
            vector<int> ans;
            for(int i=0;i<n;i++)
            {
                if(pathVis[i]==0)
                {
                    ans.push_back(i);
                }
            }
            return ans;
        }
    };