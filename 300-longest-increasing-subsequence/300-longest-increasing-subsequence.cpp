class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int lis[n];
        int res = 0;
        lis[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            lis[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    lis[i] = max(lis[i],lis[j]+1);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            res = max(res,lis[i]);
        }
        return res;
    }
};