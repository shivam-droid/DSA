class Solution {
    public:
        int func(vector<int> nums,int mid)
        {
            int total=0;
            int countd=1;
            for(int i=0;i<nums.size();i++)
            {
                if((total+nums[i])<=mid)
                {
                    total=total+nums[i];
                }
                else
                {
                    countd+=1;
                    total=nums[i];
                }
            }
            return countd;
        }
        
        int shipWithinDays(vector<int>& weights, int days) {
            int low=INT_MIN;
            int high = 0;
            for(int i=0;i<weights.size();i++)
            {
                low=max(low,weights[i]);
                high+=weights[i];
            }
            while(low<=high)
            {
                int mid = (low+high)/2;
                if(func(weights,mid)<=days)
                {
                    high=mid-1;
                }
                else low=mid+1;
            }
            return low;
        }
    };