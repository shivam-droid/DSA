class Solution {
    public:
        int totalHours(vector<int>& arr,int mid,int h)
        {
            int totalhour = 0;
            for(int i=0;i<arr.size();i++)
            {
                totalhour += (ceil)((double)(arr[i])/(double)(mid));
                if(totalhour>h){
                    return false;
                }
            }
            if(totalhour<=h)return true;
            return false;
        }
        int maxElement(vector<int>& arr)
        {
            int ans = INT_MIN;
            for(int i=0;i<arr.size();i++)
            {
                ans=max(ans,arr[i]);
            }
            return ans;
        }
        int minEatingSpeed(vector<int>& piles, int h) {
            int low=1;
            int high = maxElement(piles);
            int ans=high;
            while(low<=high)
            {
                int mid = (low+high)/2;
                if(totalHours(piles,mid,h)==true)
                {
                    high=mid-1;
                    ans=mid;
                }
                else low=mid+1;
    
            }
            return ans;
        }
    };