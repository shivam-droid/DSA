class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = (2*nums.size())-1;
        vector<int> arr(nums.size());
        while(n>=0)
        {
            while(!st.empty() && nums[n%nums.size()]>=st.top())
            {
                st.pop();
            }
            if(n<nums.size())
            {
                arr[n]=st.empty() ? -1 : st.top();
                
            }
            st.push(nums[n%nums.size()]);
            n--;
        }
        return arr;
    }
};