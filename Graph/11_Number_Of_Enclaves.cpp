class Solution {
    public:
        int numEnclaves(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> visArr(n,vector<int>(m,0));
            queue<pair<int,int>> q;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(i==0 || i==n-1 || j==0 || j==m-1)
                    {
                        if(grid[i][j]==1)
                        {
                            q.push({i,j});
                            visArr[i][j]=1;
                        }
                    }
                }
            }
            int deli[] = {-1,0,1,0};
            int delj[] = {0,1,0,-1}; 
            while(!q.empty())
            {
                auto it = q.front();
                q.pop();
                int i = it.first;
                int j = it.second;
                for(int k=0;k<4;k++)
                {
                    int newr = i + deli[k];
                    int newc = j + delj[k];
                    if(newr>=0 && newr<n && newc>=0 && newc<m && visArr[newr][newc]!=1 && grid[newr][newc]==1)
                    {
                        visArr[newr][newc]=1;
                        q.push({newr,newc});
                    }
                }
            }
            int count=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==1 && visArr[i][j]!=1)
                    {
                        count++;
                    }
                }
            }
            return count;
        }
    };