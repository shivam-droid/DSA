class Solution {
  public:
    int help(int i,int cap,vector<int>& val, vector<int>& wt,vector<vector<int>>& dp)
    {
        if(i==0)
        {
            if(wt[i]<=cap)return (int)(cap/wt[i])*val[i];
            return 0;
        }
        if(dp[i][cap]!=-1)return dp[i][cap];
        int notaken = help(i-1,cap,val,wt,dp);
        int taken = 0;
        if(wt[i]<=cap)
        {
            taken = val[i] + help(i,cap-wt[i],val,wt,dp);
        }
        return dp[i][cap]= max(taken,notaken);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,0));
        for(int i=0;i<=capacity;i++)
        {
            dp[0][i]=(int)(i/wt[0])*val[0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=capacity;j++)
            {   
                int notaken = dp[i-1][j];
                int taken = 0;
                if(wt[i]<=j)
                {
                    taken = val[i] + dp[i][j-wt[i]];
                }
                dp[i][j]=max(taken,notaken);
                
            }
        }
        return dp[n-1][capacity];
    }
};