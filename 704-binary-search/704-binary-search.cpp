class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1,mid=-1;
        bool flag=false;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(nums[mid]==target)
            {
                flag=true;
                break;          
            }
            else if(nums[mid]<target)
            {
                start=mid+1;   
            }
            else
            {
                end=mid-1;
            }
            cout<<mid<<" ";
        }
        if(flag)
            return mid;
        else
            return -1;
    }
};