public:
    int help(int i,int tar,vector<int>& arr,vector<vector<int>>& dp)
    {
        if(tar==0)return 1;
        if(i==0)
        {
            return arr[i]==tar;
        }
        
        
        if(dp[i][tar]!=-1)return dp[i][tar];
        int notake = help(i-1,tar,arr,dp);
        int take=0;
        if(arr[i]<=tar)
        take = help(i-1,tar-arr[i],arr,dp);
        return dp[i][tar] = take+notake;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        
        vector<int> narr;
        int cnt=0;
        for(auto it:arr)
        {
            if(it!=0)narr.push_back(it);
            else cnt++;
        }
        int n=narr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return pow(2,cnt)*help(n-1,target,narr,dp);
       // There's always 1 way to form sum 0 (choose no elements)
    
        
    }