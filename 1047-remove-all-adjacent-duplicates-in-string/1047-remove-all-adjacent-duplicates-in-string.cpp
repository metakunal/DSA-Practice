class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push('#');
        for(auto a:s)
        {
            if(st.top()==a)
            {
                st.pop();
            }
            else
            {
                st.push(a);
            }
        }
        string res="";
        while(!st.empty())
        {
            if(st.top()!='#')
            {
                 res+=st.top();
                st.pop();
            }
            else
            {
                st.pop();
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};