class NumArray {
public:
    
    vector<int> sqr;
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr=nums;
        int n=nums.size();
        int s=ceil(sqrt(n));
        sqr.resize(s);
        for(int i=0;i<s;i++)
        {
            sqr[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            sqr[i/s]+=nums[i];
        }
    }
    
    void update(int index, int val) {
        int s = sqr.size();
        int ni = index/s;
        sqr[ni]=sqr[ni]+val-arr[index];
        arr[index]=val;
    }
    
    int sumRange(int left, int right) {
        int s=sqr.size();
        int ans=0;
        int i=left;
        while(i<=right)
        {
            if(i%s==0)
            {
                if(i+s<=right)
                {
                    ans+=sqr[i/s];
                    i=i+s;
                }
                else
                {
                    ans+=arr[i];
                    i++;
                }
            }
            else
            {
                ans+=arr[i];
                i++;
            }
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */