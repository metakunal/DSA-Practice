class Solution {
public:
    string getSmallestString(int n, int k) {
     string res;
        int i=0;
        for(i=0;i<n;i++)
        {
            res+="a";
        }
        k=k-n;
        i=n-1;
while(k!=0)
{
    if(k<25)
    {
        res[i]='a'+k;
        k=0;
    }
    else
    {
        res[i]='a'+25;
        i--;
        k=k-25;
    }
}
        return res;
    }
};