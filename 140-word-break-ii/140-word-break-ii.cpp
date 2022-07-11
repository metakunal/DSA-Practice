class Solution {
public:
    //Pepcoding video
    void helper(string s,string ans,unordered_set<string> myset,vector<string> &res)
    {
        if(s.length()==0)
        {
            ans=ans.substr(0,ans.length()-1); //to remove spaces
            res.push_back(ans);
            return;
        }
        for(int i=0;i<s.length();i++)
        {
            string left=s.substr(0,i+1);
            if(myset.find(left)!=myset.end())
            {
                string right=s.substr(i+1);
                helper(right,ans+left+" ",myset,res);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> myset(wordDict.begin(),wordDict.end());
        vector<string> res;
        helper(s,"",myset,res);
        return res;
    }
};