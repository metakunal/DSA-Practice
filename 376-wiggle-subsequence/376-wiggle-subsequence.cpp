class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
     int n=nums.size();
        int down=1,up=1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
                up=down+1;
            if(nums[i]<nums[i+1])
                down=up+1;
        }
        return max(down,up);
    }
};