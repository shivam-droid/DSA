class Solution {
    public:
        vector<int> nse(vector<int>& arr)
        {
            stack<int> st;
            vector<int> ans(arr.size());
            int n = arr.size();
            for(int i=n-1;i>=0;i--)
            {
                while(!st.empty() && arr[st.top()]>=arr[i])
                {
                    st.pop();
                }
                ans[i]=st.empty() ? n : st.top();
                st.push(i);
            }
            return ans;
        }
        vector<int> pse(vector<int>& arr)
        {
            stack<int> st;
            vector<int> ans(arr.size());
            int n = arr.size();
            for(int i=0;i<n;i++)
            {
                while(!st.empty() && arr[st.top()]>=arr[i])
                {
                    st.pop();
                }
                ans[i]=st.empty() ? -1 : st.top();
                st.push(i);
            }
            return ans;
        }
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            int maxi=0;
            vector<int> ns = nse(heights);
            vector<int> ps = pse(heights);
            for(int i=0;i<n;i++)
            {
                maxi = max(maxi,(heights[i]*(ns[i]-ps[i]-1)));
    
            }
            return maxi;
    
        }
    };