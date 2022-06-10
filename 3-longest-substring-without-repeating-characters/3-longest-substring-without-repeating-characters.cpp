class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int i=0,j=0,n=s.length();
        unordered_set<char> set;
        int ans=0;
        while(i<n&&j<n)
        {
            if(set.find(s[j])==set.end())
            {
                set.insert(s[j]);
                j++;
                ans=max(ans,j-i);
            }
            else
            {
                set.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};