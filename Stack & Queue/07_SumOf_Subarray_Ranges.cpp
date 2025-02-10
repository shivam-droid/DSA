class Solution {
    public:
        vector<long long> nse(vector<int>& arr)
        {
            stack<int> st;
            vector<long long> ans(arr.size());
            for(int i=(arr.size()-1);i>=0;i--)
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
        vector<int> nge(vector<int>& arr)
        {
            stack<int> st;
            vector<int> ans(arr.size());
            for(int i=arr.size()-1;i>=0;i--)
            {
                while(!st.empty() && arr[st.top()]<=arr[i])
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
        vector<int> pge(vector<int>& arr)
        {
            stack<int> st;
            vector<int> ans(arr.size());
            for(int i=0;i<arr.size();i++)
            {
                while(!st.empty() && arr[st.top()]<arr[i])
                {
                    st.pop();
                }
                ans[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
            return ans;
        }
        long long subArrayRanges(vector<int>& arr) {
            long long  smallest = 0;
            long long greatest = 0;
            vector<int> ps = pse(arr);
            vector<long long> ns = nse(arr);
            vector<int> ng = nge(arr);
            vector<int> pg = pge(arr);
            for(int i=0;i<arr.size();i++)
            {
                smallest += (i - ps[i]) * (ns[i] - i) * (long long)arr[i];
                greatest += (i - pg[i]) * (ng[i] - i) * (long long)arr[i];
            }
            return greatest-smallest;
        }
    };