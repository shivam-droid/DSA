class Solution {
    public:
        vector<int> nse(vector<int>& arr)
        {
            stack<int> st;
            vector<int> ans(arr.size());
            for(int i=arr.size()-1;i>=0;i--)
            {
                while(!st.empty() && arr[st.top()]>=arr[i])
                {
                    st.pop();
                }
                ans[i] = st.empty() ? arr.size() : st.top();
                st.push(i);
    
            }
            return ans;
        }
        vector<int> pse(vector<int>& arr)
        {
            stack<int> st;
            vector<int> ans(arr.size());
            for(int i=0;i<arr.size();i++)
            {
                while(!st.empty() && arr[st.top()]>arr[i])
                {
                    st.pop();
                }
                ans[i] = st.empty() ? -1 : st.top();
                st.push(i);
    
            }
            return ans;
        }
        int sumSubarrayMins(vector<int>& arr) {
            int total =0;
            int mod=1e9 + 7;
            vector<int> ns = nse(arr);
            vector<int> ps = pse(arr);
            for(int i=0;i<arr.size();i++)
            {
                total = (int)(total + ((ns[i]-i)*(i-ps[i])*(long long)arr[i])%mod)%mod;
            }
            return total;
        }
    };