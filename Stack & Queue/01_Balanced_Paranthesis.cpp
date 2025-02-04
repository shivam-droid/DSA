#include<bits/stdc++.h>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int ss=s.size()-1;
        for(int i=0;i<=ss;i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())return false;
                char p = st.top();
                st.pop();
                if(s[i]==')')
                {
                    if(p!='(')return false;
                }
                else if(s[i]==']')
                {
                    if(p!='[')return false;
                }
                else if(s[i]=='}')
                {
                    if(p!='{')return false;
                }
            }
        }
        if(st.empty()) return true;
        else return false;
        
    }
};