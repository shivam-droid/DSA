class Solution {
    public:
        vector<int> nse(vector<int>& arr)
        {
            stack<int> st;
            vector<int> ans(arr.size());
            int n= arr.size();
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
            int m= arr.size();
            for(int i=0;i<m;i++)
            {
                while(!st.empty() && arr[st.top()]>arr[i])
                {
                    st.pop();
                }
                ans[i]=st.empty() ? -1 : st.top();
                st.push(i);
            }
            return ans;
        }
        int maxrec(vector<int>& arr)
        {
            int k = arr.size();
            int maxi=0;
            vector<int> ns = nse(arr);
            vector<int> ps = pse(arr);
            for(int i=0;i<k;i++)
            {
                int l = arr[i];
                int w = ns[i]-ps[i]-1;
                maxi = max(maxi,l*w);
            }
            return maxi;
        }
        int maximalRectangle(vector<vector<char>>& matrix) {
           
            int n = matrix.size();
            int m = matrix[0].size();
            vector<vector<int>> temp(n, vector<int>(m, 0));
            for(int j=0;j<m;j++)
            {
                int sum=0;
                for(int i=0;i<n;i++)
                {
                    if(matrix[i][j]=='1')
                    {
                        sum+=1;
                    }
                    if(matrix[i][j]=='0')
                    {
                        sum=0;
                    }
                    temp[i][j]=sum;
                }
            }
            int maxi=0;
            for(int i=0;i<n;i++)
            {
                maxi=max(maxi,maxrec(temp[i]));
            }
            return maxi;
        }
    };