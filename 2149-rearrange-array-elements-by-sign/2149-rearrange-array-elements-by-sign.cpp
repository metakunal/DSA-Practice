class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        for(auto n:nums)
        {
            if(n>=0)
                positive.push_back(n);
            else
                negative.push_back(n);
        }
        int j=0,k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {
                nums[i]=positive[j];
                j++;
            }
            else
            {
                nums[i]=negative[k];
                k++;
            }
        }
        return nums;
    }
};