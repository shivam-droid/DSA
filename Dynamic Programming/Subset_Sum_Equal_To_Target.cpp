#include<bits/stdc++.h>

bool help(int i,vector<int>& arr,int target,vector<vector<int>>& dp)
{
    if(target==0)return true;
    if(i==0)return (arr[i]==target);
    if(dp[i][target]!=-1)return dp[i][target];
    bool notaken = help(i-1,arr,target,dp);
    bool taken=false;
    //taken
    if(arr[i]<=target)
    taken = help(i-1,arr,target-arr[i],dp);
    //notaken
    
    return dp[i][target] = taken | notaken;
    
}
bool isSubsetSum(vector<int>& arr, int target) {
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return help(n-1,arr,target,dp);
}


