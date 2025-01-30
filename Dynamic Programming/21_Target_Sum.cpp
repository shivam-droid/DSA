class Solution {
public:
    int help(int i,int tar,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(i==0)
        {
            if(nums[i]==0 && tar==0)return 2;
            if(nums[i]==tar || tar==0)return 1;
            else return 0;
        }
        if(dp[i][tar]!=-1)return dp[i][tar];
        int notaken = help(i-1,tar,nums,dp);
        int taken = 0;
        if(nums[i]<=tar)
        taken = help(i-1,tar-nums[i],nums,dp);
        return dp[i][tar]=taken+notaken;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(auto it:nums)
        {
            total+=it;
        }
        //if((total-target)<0 || (total-target)%2!=0)return 0;
        int n=nums.size();
        int sum=(total+target)/2;
        if((total+target)%2!=0 || total+target<0)return 0;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return help(n-1,sum,nums,dp);
    }
};