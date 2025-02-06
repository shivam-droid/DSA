class MinStack {
public:
    stack<long long> st;
    int mini=1e9;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            mini=val;
        }
        else
        {
            if(val<mini)
            {
                long long data = 2*(long long)val-mini;
                st.push(data);
                mini=val;

            }
            else st.push(val);
        }
    }
    
    void pop() {
        if(st.empty())return;
        long long val = st.top();
        st.pop();
        if(val<mini)
        {
            mini = 2*(long long)mini-val;
        }
    }
    
    int top() {
        long long val = st.top();
        if(val<mini)
        {
            return mini;
        }
        else return val;
    }
    
    int getMin() {
        return mini;
    }
};