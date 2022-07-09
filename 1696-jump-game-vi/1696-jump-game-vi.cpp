class Solution {
public:
    // int helper(vector<int>& nums,int k,int i,vector<int> &dp)
    // {
    //     if(dp[i]!=INT_MIN)
    //         return dp[i];
    //     for(int j=1;j<=k;j++)
    //     {
    //         if(i+j<nums.size())
    //             dp[i]=max(dp[i],nums[i]+helper(nums,k,i+j,dp));
    //     }
    //     return dp[i];
    // }
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>> pq;
        int score[n];
        for(int i=n-1;i>=0;i--)
        {
            while(pq.size() && pq.top().second>i+k)
                pq.pop();
            score[i]=nums[i];
            score[i]+=(pq.size()?pq.top().first:0);
            pq.push({score[i],i});
        }
        return score[0];
    }
};