class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        stack<int> st;
        int n=nums2.size()-1;
        while(n>=0)
        {
            while(!st.empty() && st.top()<=nums2[n])
            {
                st.pop();
            }
            m[nums2[n]] = st.empty() ? -1 : st.top();
            st.push(nums2[n]);
            n--;
        }
        int n2 = nums1.size()-1;
        vector<int> ans(n2+1);
        while(n2>=0)
        {
            ans[n2] = m[nums1[n2]];
            n2--;
        }
        return ans;
    }
};