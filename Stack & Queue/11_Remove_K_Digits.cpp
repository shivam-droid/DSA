class Solution {
    public:
        string removeKdigits(string num, int k) {
            stack<char> st;
            int n = num.size();
            if(k==n || k>n)return "0";
            for(int i=0;i<n;i++)
            {
                while(!st.empty() && num[i]-'0'<st.top()-'0' && k>0)
                {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
    
            }
            while(k>0){
            st.pop();
            k--;
            }
            if(st.empty())return "0";
            string result;
            while (!st.empty()) {
                result += st.top();
                st.pop();
            }
    
            // Reverse the result (since we inserted from the back)
            reverse(result.begin(), result.end());
    
            // Remove leading zeros
            int start = 0;
            while (start < result.size() && result[start] == '0') {
                start++;
            }
            result = result.substr(start);
    
            return result.empty() ? "0" : result;
    
    
        }
    };