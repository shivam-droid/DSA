class Solution {
    public:
        int func(vector<int> nums,int mid)
        {
            int count=0;
            for(int i=0;i<nums.size();i++)
            {
                count+=(ceil)((double)(nums[i])/(double)(mid));
            }
            return count;
        }
    
        int maxElement(vector<int> nums)
        {
            int maxi=INT_MIN;
            for(auto it:nums)
            {
                maxi=max(maxi,it);
            }
            return maxi;
        }
        int smallestDivisor(vector<int>& nums, int threshold) {
            int low=1;
            int high=maxElement(nums);
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(func(nums,mid)<=threshold)
                {
                    
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            return low;
        }
    };