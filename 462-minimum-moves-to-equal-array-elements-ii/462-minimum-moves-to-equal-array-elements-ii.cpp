class Solution {
public:
    int minMoves2(vector<int>& nums) {
     sort(nums.begin(),nums.end());
    int n=nums.size();
        int ans=0;
        int c=nums[n/2];
        for(auto a:nums)
        {
            ans+=abs(a-c);
        }
        return ans;
    }
};