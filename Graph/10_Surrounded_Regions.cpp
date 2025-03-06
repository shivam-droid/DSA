class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            int n = board.size();
            int m = board[0].size();
            vector<vector<int>> visArr(n,vector<int>(m,0));
            queue<pair<int,int>> q;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(i==0 || i==n-1 || j==0 || j==m-1) 
                    {
                        if(board[i][j]=='O')
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
                int row = it.first;
                int col = it.second;
                for(int k=0;k<4;k++)
                {
                    int newr = row + deli[k];
                    int newc = col + delj[k];
                    if(newr>=0 && newr<n && newc>=0 && newc<m && board[newr][newc]=='O' && visArr[newr][newc]!=1)
                    {
                        visArr[newr][newc]=1;
                        q.push({newr,newc});
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(visArr[i][j]!=1 && board[i][j]=='O')
                    {
                        board[i][j]='X';
                    }
                }
            }
    
        }
    };