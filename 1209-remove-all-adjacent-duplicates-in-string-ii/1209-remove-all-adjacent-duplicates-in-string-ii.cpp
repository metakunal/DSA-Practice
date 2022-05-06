class Solution {
public:
    string removeDuplicates(string s, int k) {
     stack<pair<char,int>> stk;
    stk.push({'#',1});
        for(auto c:s)
        {
            if(c!=stk.top().first)
            {
                stk.push({c,1});
            }
            else
            {
                auto prev = stk.top();
                stk.pop();
                stk.push({c,prev.second+1});
            }
            if(stk.top().second==k) stk.pop();
        }
        string res="";
        while(!stk.empty())
        {
            auto t = stk.top();
            stk.pop();
            if(t.first!='#')
            {
             while(t.second--)
             {
                 res+=t.first;
             }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};