class Solution {
public:
    int help(int i,int tar,vector<int>& arr,vector<vector<int>>& dp)
    {
        if(tar==0)return 1;
        if(i==0){
            return (tar%arr[i]==0);
        }
        if(dp[i][tar]!=-1)return dp[i][tar];
        int notaken = help(i-1,tar,arr,dp);
        int taken=0;
        if(arr[i]<=tar)taken = help(i,tar-arr[i],arr,dp);
        
        return dp[i][tar] = taken+notaken;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return help(n-1,amount,coins,dp);
    }
};