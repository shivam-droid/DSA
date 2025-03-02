class Solution {
    public:
        vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int n = mat.size();
            int m = mat[0].size();
            int low=0;
            int high=m-1;
            while(low<=high)
            {
                int mid = (low+high)/2;
                int row=-1;
                int max=INT_MIN;
                for(int i=0;i<n;i++)
                {
                    if(mat[i][mid]>max){
                        max=mat[i][mid];
                        row=i;
                    }
                }
                int left = mid-1>=0 ? mat[row][mid-1] : -1;
                int right = mid+1<m ? mat[row][mid+1] : -1;
                if(left<mat[row][mid] && right<mat[row][mid])
                {
                    return {row,mid};
                }
                if(left>mat[row][mid])
                {
                    high=mid-1;
                }
                else low=mid+1;
            }
            return {-1,-1};
        }
    };