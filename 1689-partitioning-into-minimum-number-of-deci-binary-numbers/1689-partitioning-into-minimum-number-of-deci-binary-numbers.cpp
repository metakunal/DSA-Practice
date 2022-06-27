class Solution {
public:
    int minPartitions(string n) {
        int mx=INT_MIN;
        for(int i=0;i<n.length();i++)
        {
            int b=n[i]-'0';
            mx=max(mx,b);
        }
        return mx;
    }
};