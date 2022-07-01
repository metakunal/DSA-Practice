class Solution {
	public:
   	string longestPalindrome(string s) {   
	    int n=s.length();
        int ans=INT_MIN;
        int start=0,end=0;
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
                {
                   if(j-i+1>ans)
                   {
                       ans=j-i+1;
                       start=i,end=j;
                   }
                }
                    
            }
        }
        string res="";
        for(int i=start;i<=end;i++)
            res+=s[i];
        return res;

	}
};