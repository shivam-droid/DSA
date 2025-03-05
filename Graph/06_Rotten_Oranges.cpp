class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            queue<pair<pair<int,int>,int>> q;
            vector<vector<int>> visArr(n,vector<int>(m,0));
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==2)
                    {
                        q.push({{i,j},0});
                        visArr[i][j]=1;
                    }
                }
            }
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            int time=0;
            while(!q.empty())
            {
                auto it = q.front();
                q.pop();
                int row = it.first.first;
                int col = it.first.second;
                time = it.second;
                for(int k=0;k<4;k++)
                {
                    int newrow = row + delrow[k];
                    int newcol = col + delcol[k];
                    if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && visArr[newrow][newcol]!=1
                    && grid[newrow][newcol]==1)
                    {
                        visArr[newrow][newcol]=1;
                        q.push({{newrow,newcol},time+1});
                        
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==1 && visArr[i][j]!=1)
                    {
                        return -1;
                    }
                }
            }
            return time;
        }
    };