class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
     int mod=1000000007;
        horizontalCuts.push_back(h);
             horizontalCuts.push_back(0);
    verticalCuts.push_back(w);
            verticalCuts.push_back(0);
        sort(horizontalCuts.rbegin(),horizontalCuts.rend());                                      sort(verticalCuts.rbegin(),verticalCuts.rend());
        int mh=INT_MIN,mw=INT_MIN;
        for(int i=0;i<horizontalCuts.size()-1;i++)
        {
            mh=max(mh,(horizontalCuts[i]-horizontalCuts[i+1]));
        }
         for(int i=0;i<verticalCuts.size()-1;i++)
        {
            mw=max(mw,verticalCuts[i]-verticalCuts[i+1]);
        }
       return (long)mh * mw % 1000000007;
    }
};