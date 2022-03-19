class Solution {
public:
    string simplifyPath(string path) {
     string temp;
    vector<string> stk;
        string res="";
            stringstream ss(path);
        while(getline(ss,temp,'/'))
        {
            if(temp=="."|| temp=="")
                continue;
            else if(temp==".." && !stk.empty())
            {
                stk.pop_back();
            }
            else if(temp!="..")
                stk.push_back(temp);
        }
        for(auto a:stk)
        {
             res+="/";
            res+=a;
        }
        return res.empty()?"/":res;
    }
};