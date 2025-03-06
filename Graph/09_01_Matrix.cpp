class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int n = mat.size();
            int m = mat[0].size();
            vector<vector<int>> visArr(n,vector<int>(m,0));
            queue<pair<pair<int,int>,int>> q;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(mat[i][j]==0)
                    {
                        q.push({{i,j},0});
                    }
                }
            }
            int deli[] = {-1,0,1,0};
            int delj[] = {0,1,0,-1};
            while(!q.empty())
            {
                auto it = q.front();
                q.pop();
                int i = it.first.first;
                int j = it.first.second;
                int dis = it.second;
                for(int k=0;k<4;k++)
                {
                    int newr = i + deli[k];
                    int newc = j + delj[k];
                    if(newr >=0 && newr<n && newc>=0 && newc<m && mat[newr][newc]==1 && visArr[newr][newc]==0)
                    {
                        q.push({{newr,newc},dis+1});
                        visArr[newr][newc]=dis+1;
                        //ans[newr][newc]=dis+1;
                    }
                }
            }
            return visArr;
        }
    };