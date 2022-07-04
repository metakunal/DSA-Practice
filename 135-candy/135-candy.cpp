class Solution {
public:
    int candy(vector<int>& ratings) {
     int n=ratings.size();
     vector<int> left_arr(n,1);
             vector<int> right_arr(n,1);
        for(int i=0;i<n-1;i++)
        {
            if(ratings[i+1]>ratings[i])
                left_arr[i+1]=left_arr[i]+1;
        }
        for(int i=n-1;i>=1;i--)
        {
            if(ratings[i-1]>ratings[i])
                right_arr[i-1]=right_arr[i]+1;
        }
        for(int i=0;i<n;i++)
            ratings[i]=max(left_arr[i],right_arr[i]);
        return accumulate(ratings.begin(),ratings.end(),0);
    }
};