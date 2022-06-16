class Solution {
public:
    
    
    int ans=INT_MAX;
    
    void helper(int inx, vector<int>& nums,int count){
        if(inx >= nums.size()-1){
            ans=min(ans,count);
            return;
        }
        
        for(int i=1; i<=nums[inx]; i++){             
             helper(inx + i, nums,count+1);
        }
    }

    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=0;
        for(int i=1;i<n;i++)
            dp[i]=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(j+nums[j]>=i)
                {
                    if(dp[j]!=INT_MAX)
                        dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};