class Solution {
    public:
        void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visArr)
        {
            int n = grid.size();
            int m = grid[0].size();
            visArr[i][j]=1;
            queue<pair<int,int>> q;
            q.push({i,j});
            int deli[] = {-1,0,1,0};
            int delj[] = {0,1,0,-1};
            while(!q.empty())
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int newr = deli[k]+row;
                    int newc = delj[k]+col;
                    if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]=='1'
                    && visArr[newr][newc]!=1)
                    {
                        visArr[newr][newc]=1;
                        q.push({newr,newc});
                    }
                }
            }
        }
        int numIslands(vector<vector<char>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            int count=0;
            vector<vector<int>> visArr(n,vector<int>(m,0));
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]=='1' && visArr[i][j]!=1)
                    {
                        count++;
                        dfs(i,j,grid,visArr);
                    }
                }
            }
            return count;
        }
    };