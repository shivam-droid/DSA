class Solution {
    public:
        int trap(vector<int>& height) {
            vector<int> nextmax(height.size());
            int n = height.size()-1;
            int ind = height.size()-1;
            while(n>=0)
            {
                if(n==ind)
                {
                    nextmax[n]=height[n];
                    n--;
                }
                else
                {
                    nextmax[n]=max(height[n],nextmax[n+1]);
                    n--;
                }
            }
            int total=0;
            for(int i=1;i<height.size();i++)
            {
                int lastmax = max(height[i],height[i-1]);
    
                if(height[i]<lastmax && height[i]<nextmax[i])
                {
                    total+=(min(lastmax,nextmax[i])-height[i]);
                }
                height[i]=lastmax;
            }
            return total;
     
        }
    };