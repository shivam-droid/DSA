class Solution {
    public:
        int help(int i,int buy,int k,vector<int>& prices,vector<vector<vector<int>>>& dp)
        {
            if(i==prices.size() || k==0)return 0;
            if(dp[i][buy][k]!=-1)return dp[i][buy][k];
            int profit = 0;
            if(buy)
            {
                profit = max((-prices[i] + help(i+1,0,k,prices,dp)),(0 + help(i+1,1,k,prices,dp)));
            }
            else
            {
                profit = max((prices[i] + help(i+1,1,k-1,prices,dp)),(0 + help(i+1,0,k,prices,dp)));
            }
            return dp[i][buy][k] = profit;
        }
        int maxProfit(int k, vector<int>& prices) {
            int n = prices.size();
            vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1))); //with k given transactions
            return help(0,1,k,prices,dp);
        }
    };