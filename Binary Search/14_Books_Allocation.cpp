class Solution {
    public:
      int possible(vector<int> arr,int mid)
      {
          int total=0;
          int count=0;
          for(auto it:arr)
          {
              if(total+it<=mid)
              {
                  total+=it;
              }
              else
              {
                  count++;
                  total=it;
              }
          }
          count++;
          return count++;
      }
      int findPages(vector<int> &arr, int k) {
          // code here
          int n = arr.size();
          int low=INT_MIN;
          int high = 0;
          for(int i=0;i<n;i++)
          {
              low=max(low,arr[i]);
              high+=arr[i];
          }
          
          if(k>n)return -1;
          if(k==n)return low;
          while(low<=high)
          {
              int mid = (low+high)/2;
              if(possible(arr,mid)<=k)
              {
                  high=mid-1;
              }
              else low=mid+1;
          }
          return low;
      }
  };