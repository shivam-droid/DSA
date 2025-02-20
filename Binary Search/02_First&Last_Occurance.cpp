class Solution {
    public:
        int lb(vector<int>& arr,int tar)
        {
            int n = arr.size();
            int low=0;
            int high=n-1;
            int ans=n;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(arr[mid]>=tar)
                {
                    ans=mid;
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            return ans;
        }
        int ub(vector<int>& arr,int tar)
        {
            int n = arr.size();
            int low=0;
            int high=n-1;
            int ans=n;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(arr[mid]>tar)
                {
                    ans=mid;
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            return ans;
        }
        vector<int> searchRange(vector<int>& nums, int target) {
            int lwb = lb(nums,target);
            int uwb = ub(nums,target);
            if(lwb==nums.size() || nums[lwb]!=target)return {-1,-1};
            return {lwb,uwb-1};
        }
    };