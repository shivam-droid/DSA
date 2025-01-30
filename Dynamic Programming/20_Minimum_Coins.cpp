class Solution {
public:
    int help(int i,int amt,vector<int>& coins,vector<vector<int>>& dp)
    {
        if(i==0)
        {
            if(amt%coins[i]==0)return amt/coins[i];
            else return 1e9;
        }
        if(dp[i][amt]!=-1)return dp[i][amt];

        int take=INT_MAX;
        if(coins[i]<=amt)
        take = 1 + help(i,amt-coins[i],coins,dp);
        int notake = 0 + help(i-1,amt,coins,dp);
        return dp[i][amt] = min(take,notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int val = help(coins.size()-1,amount,coins,dp);
        if(val==1e9)return -1;
        else return val;
    }
};