class Solution {
    public:
      // Function to find if there is a celebrity in the party or not.
      int celebrity(vector<vector<int> >& mat) {
          // code here
          int n = mat.size();
          int top=0;
          int down=n-1;
          while(top<down)
          {
              if(mat[top][down]==1)top++;
              else if(mat[down][top]==1)down--;
              else
              {
                  top++;
                  down--;
              }
              
          }
          if(top>down)return -1;
          for(int i=0;i<n;i++)
          {
              if(i==top)continue;
              if(mat[top][i]==1)return -1;
              if(mat[i][top]==0)return -1;
          }
          return top;
      }
  };