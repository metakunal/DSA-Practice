class Solution {
public:
    long long numberOfWays(string s) {
     int totZeroes=0,totOnes=0;
        long long ans=0;
        for(auto c:s)
        {
            if(c=='0')
                totZeroes++;
            else
                totOnes++;
        }
        int currZeroes=0;
        int currOnes=0;
        if(s[0]=='0')
            currZeroes++;
        else
            currOnes++;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]=='0')
            {
                ans=ans+(currOnes*(totOnes-currOnes));
                currZeroes++;
            }
            else
            {
                ans=ans+(currZeroes*(totZeroes-currZeroes));
                currOnes++;
            }
        }
        return ans;
    }
};