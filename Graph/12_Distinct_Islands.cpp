class Solution {
    public:
      void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visArr,
      vector<pair<int,int>>& vec,int basei,int basej)
      {
          int n = grid.size();
          int m = grid[0].size();
          visArr[i][j]=1;
          int row = basei-i;
          int col = basej-j;
          vec.push_back({row,col});
          int deli[] = {-1,0,1,0};
          int delj[] = {0,1,0,-1};
          for(int k=0;k<4;k++)
          {
              int newr = i + deli[k];
              int newc = j + delj[k];
              if(newr>=0 && newr<n && newc>=0 && newc<m && visArr[newr][newc]!=1
              && grid[newr][newc]==1)
              {
                  dfs(newr,newc,grid,visArr,vec,basei,basej);
              }
          }
          
      }
      int countDistinctIslands(vector<vector<int>>& grid) {
          // code here
          int n = grid.size();
          int m = grid[0].size();
          vector<vector<int>> visArr(n,vector<int>(m,0));
          
          set<vector<pair<int,int>>> s;
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<m;j++)
              {
                  if(grid[i][j]==1 && visArr[i][j]!=1)
                  {
                      vector<pair<int,int>> vec;
                      dfs(i,j,grid,visArr,vec,i,j);
                      s.insert(vec);
                      
                  }
              }
          }
          return s.size();
      }
  };