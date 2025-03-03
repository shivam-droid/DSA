class Solution {
    public:
        void dfs(int node,vector<vector<int>>& adjList,vector<int>& visList)
        {
            visList[node]=1;
            for(auto it:adjList[node])
            {
                if(visList[it]!=1)
                {
                    dfs(it,adjList,visList);
                }
            }
        }
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
            vector<vector<int>> adjList(n);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(isConnected[i][j]==1 && i!=j)
                    {
                        adjList[i].push_back(j);
                        adjList[j].push_back(i);
                    }
                }
            }
            vector<int> visList(n,0);
            int count=0;
            for(int i=0;i<n;i++)
            {
                if(visList[i]!=1)
                {
                    count++;
                    dfs(i,adjList,visList);
                }
            }
            return count;
        }
    };