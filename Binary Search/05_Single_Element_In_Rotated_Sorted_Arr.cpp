class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int n = nums.size();
            int low=1;
            int high=n-2;
            if(n==1)return nums[0];
            if(nums[0]!=nums[low])return nums[0];
            if(nums[n-1]!=nums[high])return nums[n-1];
            while(low<=high)
            {
                int mid = (low+high)/2;
                if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])return nums[mid];
                if((mid%2!=0 && nums[mid-1]==nums[mid]) || (mid%2==0 && nums[mid]==nums[mid+1]))
                {
                    low=low+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            return -1;
        }
    };