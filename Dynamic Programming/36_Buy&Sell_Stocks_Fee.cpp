class Solution {
    public:
        int help(int i,int buy,vector<int>& prices,vector<vector<int>>& dp,int fee)
        {
            if(i==prices.size())return 0;
            if(dp[i][buy]!=-1)return dp[i][buy];
            int profit = 0;
            if(buy)
            {
                profit = max((-prices[i] + help(i+1,0,prices,dp,fee)),(0 + help(i+1,1,prices,dp,fee)));
            }
            else
            {
                profit = max((prices[i] - fee + help(i+1,1,prices,dp,fee)),(0 + help(i+1,0,prices,dp,fee)));
            }
            return dp[i][buy] = profit;
        }
        int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
            vector<vector<int>> dp(n,vector<int>(2,-1)); //with fee on each transaction
            return help(0,1,prices,dp,fee);
        }
    };