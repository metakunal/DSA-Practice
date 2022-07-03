class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
     int n=nums.size();
        int ma=1,mi=1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
                ma=mi+1;
            if(nums[i]<nums[i+1])
                mi=ma+1;
        }
        return max(ma,mi);
    }
};