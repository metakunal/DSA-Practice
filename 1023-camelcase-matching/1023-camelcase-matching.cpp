class Solution {
public:
    bool isMatch(string q,string pattern)
    {
        int i=0;
        for(auto c:q)
        {
            if(i<pattern.length() && pattern[i]==c)
                i++;
            else if(c<'a')
                return false;
        }
        return i==pattern.length();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for(auto q:queries)
        {
            res.push_back(isMatch(q,pattern));
        }
        return res;
    }
};