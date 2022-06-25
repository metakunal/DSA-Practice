class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int wc=0;
        vector<int> nums2=nums;
        bool flag=true;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<=nums[i+1])
                continue;
            else
            {
                nums2[i+1]=nums2[i];
                nums[i]=nums[i+1];
                break;                
            }
        }
        for(auto n:nums2)
            cout<<n<<" ";
        cout<<endl;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            return true;
        flag=true;
        for(int i=0;i<nums2.size()-1;i++)
        {
            if(nums2[i]>nums2[i+1])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            return true;
       return false;
    }
};