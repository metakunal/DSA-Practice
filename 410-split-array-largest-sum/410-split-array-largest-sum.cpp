class Solution {
public:
   bool ok(int maxsum,vector<int>& nums,int n,int m){
        m--;
        int sum = 0;
        for(auto& x:nums){
            if(sum+x<=maxsum){
                sum += x;
            }
            else{
                m--;
                sum = x;
            }
        }
        return m>=0;
    }
    int splitArray(vector<int>& nums, int m) {
        int l = INT_MIN,r = 0,n = nums.size();
        for(auto& x:nums){
            r += x;
            l = max(l,x);
        }
        int ans = r;
        while(l<=r){
            int mid = (l+r)/2;
            if(ok(mid,nums,n,m)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};