class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        int n=cardPoints.size();
        int ans=0;
        for(int i=0;i<(n-k);i++)
        {
            ans+=cardPoints[i];
        }
        int curr=ans;
        cout<<curr<<" ";
        for(int i=0;i<k;i++)
        {
            curr-=cardPoints[i];
            curr+=cardPoints[n-k+i];
            ans=min(curr,ans);
            cout<<ans<<" ";
        }
        cout<<n-k<<" "<<ans;
        return totalSum-ans;
    }
};