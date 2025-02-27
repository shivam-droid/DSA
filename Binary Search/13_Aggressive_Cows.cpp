class Solution {
  public:
    int possible(vector<int>& stalls,int mid,int k)
    {
        sort(stalls.begin(),stalls.end());
        int last=0;
        k=k-1;
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-stalls[last]>=mid)
            {
                last=i;
                k--;
            }
        }
        if(k<=0)return true;
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high = stalls[stalls.size()-1]-stalls[0];
        int ans;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(possible(stalls,mid,k))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};