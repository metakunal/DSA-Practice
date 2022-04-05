class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
           if(n==1)
            return 0;
    int l=0, r=n-1;
        int ans=INT_MIN;
        while(l<r)
        {
            ans=max(ans,((r-l)*min(height[l],height[r])));
            if(height[l]<=height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};