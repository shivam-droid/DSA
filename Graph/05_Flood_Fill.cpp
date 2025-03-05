class Solution {
    public:
        void dfs(int i,int j,vector<vector<int>>& image,vector<vector<int>>& visArr,int color,int prevcolor)
        {
            visArr[i][j]=1;
            image[i][j]=color;
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            for(int k=0;k<4;k++)
            {
                int newrow = i + delrow[k];
                int newcol = j + delcol[k];
                if(newrow>=0 && newrow<image.size() && newcol>=0 && newcol<image[0].size() && 
                image[newrow][newcol]==prevcolor && visArr[newrow][newcol]!=1)
                {
                    dfs(newrow,newcol,image,visArr,color,prevcolor);
                }
            }
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int n = image.size();
            int m = image[0].size();
            if(image[sr][sc]==color)return image;
            vector<vector<int>> visArr(n,vector<int>(m,0));
            dfs(sr,sc,image,visArr,color,image[sr][sc]);
            return image;
        }
    };