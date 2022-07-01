class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<dp.size();i++,j++)
            {
                if(g==0)
                {
                    dp[i][j]=true;
                }else if(g==1)
                {
                    if(s[i]==s[j])
                        dp[i][j]=true;
                }else
                {
                    if(s[i]==s[j]&&dp[i+1][j-1]==true)
                        dp[i][j]=true;
                }
                if(dp[i][j]==true)
                    count++;
            }
        }
        return count;
    }
};