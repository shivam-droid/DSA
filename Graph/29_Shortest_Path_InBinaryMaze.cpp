class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            if(grid[0][0]==1)return -1;
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> dist(n,vector<int>(m,1e9));
            dist[0][0]=1;
            queue<pair<int,pair<int,int>>> q;
            q.push({1,{0,0}});
            int delr[] = {-1,-1,-1,0,1,1,1,0}; // Row changes
            int delc[] = {-1,0,1,1,1,0,-1,-1}; 
            while(!q.empty())
            {
                auto it = q.front();
                q.pop();
                int srcDis = it.first;
                int row = it.second.first;
                int col = it.second.second;
                if(row==n-1 && col==m-1)return dist[row][col];
                for(int i=0;i<8;i++)
                {
                    int newr=row+delr[i];
                    int newc=col+delc[i];
                    
                    if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==0 && srcDis + 1 <dist[newr][newc])
                    {
                        
                        dist[newr][newc]=srcDis + 1;
                        q.push({srcDis+1,{newr,newc}});
    
                    }
                }
            }
            return -1;
        }
    };