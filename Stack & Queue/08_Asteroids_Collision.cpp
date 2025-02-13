class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            list<int> st;
            int n = asteroids.size();
            for(int i=0;i<n;i++)
            {
                if(asteroids[i]>0)st.push_back(asteroids[i]);
                else
                {
                    while(!st.empty() && st.back()>0 && st.back()<abs(asteroids[i]))
                    {
                        st.pop_back();
                    }
                    if(!st.empty() && st.back()==abs(asteroids[i]))st.pop_back();
                    else if(st.back()>abs(asteroids[i]))continue;
                    else if(st.empty() || asteroids[i]<0)
                    {
                        st.push_back(asteroids[i]);
                    }
                }
            }
            vector<int> ans(st.begin(),st.end());
            return ans;
        }
    };