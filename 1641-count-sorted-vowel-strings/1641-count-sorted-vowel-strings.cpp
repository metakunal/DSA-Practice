class Solution {
public:
    int countVowelStrings(int n) {
     vector<int> res(5,1);
        for(int i=0;i<5;i++)
        {
            res[i]=1;
        }
        
        for(int j=1;j<n;j++)
        {
            for(int i=3;i>=0;i--)
            {
                res[i]+=res[i+1];
            }
        }
        int sum=0;
        for(auto r:res)
        {
            cout<<r<<" ";
            sum+=r;
        }
        return sum;
    }
};