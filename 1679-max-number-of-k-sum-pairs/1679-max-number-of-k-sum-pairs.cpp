class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        for(auto n:nums)
        {
            mp[n]++;
        }
        for(auto n:nums)
        {
            if(mp[n])
            {
                mp[n]--;
            if(mp[k-n])
            {
                mp[k-n]--;
                count++;
            }
            else
                {
                    mp[n]++;
                }
                }
        }
        return count;
    }
};