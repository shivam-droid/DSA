class Solution {
  public:
    int help(int i,int n,vector<int>& price,vector<vector<int>>& dp)
    {
        if(i==0)
        {
            return (int)(n/(i+1))*price[i];
        }
        if(dp[i][n]!=-1)return dp[i][n];
        int notake = 0 + help(i-1,n,price,dp);
        int take=INT_MIN;
        if(i+1<=n)
        {
            take = price[i]+help(i,n-(i+1),price,dp);
        }
        return dp[i][n] = max(notake,take);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return help(n-1,n,price,dp);
    }
};