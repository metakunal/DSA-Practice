class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(auto c : ops)
        {
            if(c=="+")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.push(a);
                st.push(a+b);
            }
            else if(c=="D")
            {
                int a=st.top();
                st.push(2*a);
            }
            else if(c=="C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(c));
            }
        }
          int ans=0;
         while(!st.empty())
         {
             ans+=st.top();
             st.pop();
         }
        return ans;
    }
};