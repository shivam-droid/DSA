class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            int n = heights.size();
            int m = heights[0].size();
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
            vector<vector<int>> dist(n,vector<int>(m,1e9));
            dist[0][0]=0;
            pq.push({0,{0,0}});
            int delr[] = {-1,0,1,0};
            int delc[] = {0,1,0,-1};
            while(!pq.empty())
            {
                auto it = pq.top();
                pq.pop();
                int eff = it.first;
                int row = it.second.first;
                int col = it.second.second;
                if(row==n-1 && col==m-1)return eff;
                for(int k=0;k<4;k++)
                {
                    int newr = row + delr[k];
                    int newc = col + delc[k];
                    
                    if(newr>=0 && newr<n && newc>=0 && newc<m)
                    {
                        int neweff = max(eff,abs(heights[row][col] - heights[newr][newc]));
                        if(neweff<dist[newr][newc])
                        {
                            dist[newr][newc]=neweff;
                            pq.push({neweff,{newr,newc}});
                        }
                    }
                }
            }
            return 0;
        }
    };