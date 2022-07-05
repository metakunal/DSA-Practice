class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_set<int> us;
        for(auto n:nums)
        {
            us.insert(n);
        }
        int max_streak=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            int curr_num=nums[i];
            int current_streak=1;
            if(us.find(curr_num-1)==us.end())
            {
                while(us.find(curr_num+1)!=us.end())
                {
                    curr_num+=1;
                    current_streak+=1;
                }
                max_streak=max(max_streak,current_streak);
            }
        }
        return max_streak;
    }
};