class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n,1);
            vector<int> hash(n);
            sort(nums.begin(),nums.end());
            int maxi=0;
            int lastindex=0;
            for(int i=0;i<n;i++)
            {
                hash[i]=i;
                for(int ind=0;ind<i;ind++)
                {
                    if(nums[i]%nums[ind]==0 && 1+dp[ind]>dp[i])
                    {
                        dp[i]=1+dp[ind];
                        hash[i]=ind;
                    }
                }
                if(dp[i]>maxi)
                {
                    maxi=dp[i];
                    lastindex=i;
                }
            }
            vector<int> temp;
            temp.push_back(nums[lastindex]);
            while(hash[lastindex]!=lastindex)
            {
                lastindex = hash[lastindex];
                temp.push_back(nums[lastindex]);
            }
            reverse(temp.begin(),temp.end());
            return temp;
        }
    };