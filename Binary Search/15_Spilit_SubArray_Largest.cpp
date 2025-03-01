class Solution {
    public:
        int possible(vector<int> arr,int mid)
        {
            int total=0;
            int count=1;
            for(int i=0;i<arr.size();i++)
            {
                if(total+arr[i]<=mid)
                {
                    total+=arr[i];
                }
                else
                {
                    count++;
                    total=arr[i];
                }
            }
            return count;
        }
        int splitArray(vector<int>& nums, int k) {
            int low=INT_MIN;
            int high=0;
            for(int i=0;i<nums.size();i++)
            {
                high+=nums[i];
                low=max(low,nums[i]);
            }
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(possible(nums,mid)<=k)
                {
                    high=mid-1;
                }
                else low=mid+1;
            }
            return low;
        }
    };