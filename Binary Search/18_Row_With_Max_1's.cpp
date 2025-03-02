class Solution {
    public:
      int lb(vector<int> arr,int k)
      {
          int low=0;
          int high=arr.size()-1;
          int ans=arr.size();
          while(low<=high)
          {
              int mid = (low+high)/2;
              if(arr[mid]>=k)
              {
                  ans=mid;
                  high=mid-1;
              }
              else low=mid+1;
          }
          return (arr.size()-ans);
      }
      int rowWithMax1s(vector<vector<int>> &arr) {
          // code here
          int totalcount=0;
          int index=-1;
          for(int i=0;i<arr.size();i++)
          {
              int count=lb(arr[i],1);
              if(count>totalcount)
              {
                  totalcount=count;
                  index=i;
              }
              
          }
          return index;
      }
  };