class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target = sum-x;
        unordered_map<int,int> mp;
        int presum=0;
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            presum+=nums[i];
            if(presum==target)
                res=i+1;
            if(mp.find(presum)==mp.end())
                mp.insert({presum,i});
            if(mp.find(presum-target)!=mp.end())
                res=max(res,i-mp[presum-target]);
        }
        return res==INT_MIN?-1:nums.size()-res;
    }
};