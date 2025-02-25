class Solution {
    public:
        int func(vector<int> arr,int mid,int k)
        {
            int count=0;
            int totalb=0;
            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]<=mid)
                {
                    count++;
                    
                }
                else
                {
                    totalb += count/k;
                    count=0;
                }
                
    
            }
            totalb+=count/k;
            return totalb;
        }
        
        int minDays(vector<int>& bloomDay, int m, int k) {
            int low=INT_MAX;
            int high=INT_MIN;
            for(int i=0;i<bloomDay.size();i++)
            {
                low = min(low,bloomDay[i]);
                high = max(high,bloomDay[i]);
    
            }
            int ans=high;
            if(bloomDay.size()<(long long)(m)*(long long)(k))return -1;
            while(low<=high)
            {
                int mid = (low+high)/2;
                if(func(bloomDay,mid,k)==m)
                {
                    high=mid-1;
                    ans=min(ans,mid);
                }
                else if(func(bloomDay,mid,k)<m)
                {
                    low=mid+1;
    
                }
                else high=mid-1;
            }
            return ans;
        }
    };