class Solution {
public:
    static bool compare(const string s1,const string s2)
    {
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        unordered_map<string,int> dp;
        int res=1;
        for(auto word:words)
        {
            dp[word]=1;
            for(int i=0;i<word.size();i++)
            {
                string prev=word.substr(0,i)+word.substr(i+1);
                if(dp.find(prev)!=dp.end())
                {
                    dp[word]=dp[prev]+1;
                    res=max(res,dp[word]);
                }
            }
        }
        return res;
    }
};