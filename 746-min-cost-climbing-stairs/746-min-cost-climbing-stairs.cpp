class Solution {
public:
    int helper(vector<int> &cost,int i,vector<int> &dp)
    {
        if(i>=cost.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=cost[i]+min(helper(cost,i+1,dp),helper(cost,i+2,dp));   
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // return min(helper(cost,0,dp),helper(cost,1,dp));
                vector<int> dp(cost.size(),-1);
int n=cost.size();
        for(int i=0;i<n;i++)
        {
            if(i<2)
                dp[i]=cost[i];
            else
                dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};