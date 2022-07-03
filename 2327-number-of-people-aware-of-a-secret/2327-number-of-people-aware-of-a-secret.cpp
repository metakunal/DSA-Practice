class Solution {
    int MOD=1000000007;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
     vector<int> dp(n,0);
        dp[0]=1;
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+delay;j<min(i+forget,n);j++)
            {
                dp[j]=(dp[j]+dp[i])%MOD;
            }
        }
        for(auto d:dp)
            cout<<d<<" ";
        for(int i=max(0,n-forget);i<n;i++)
            res=(res+dp[i])%MOD;
        return res;
    }
};