class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n,1);
            int maxi=1;
            for(int i=0;i<n;i++)
            {
                for(int ind=0;ind<i;ind++)
                {
                    if(nums[ind]<nums[i] && 1+dp[ind]>dp[i])
                    {
                        dp[i]=1+dp[ind];
                    }
                }
                maxi = max(maxi,dp[i]);
            }
            return maxi;
        }
    };