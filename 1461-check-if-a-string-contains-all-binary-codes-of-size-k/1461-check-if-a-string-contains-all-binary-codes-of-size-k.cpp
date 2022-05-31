class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length(); 
        unordered_set<string> mp;
        for(int i=0;i<=n-k;i++)
        {
            mp.insert(s.substr(i,k));
        }
        // for(auto m:mp)
        // {
        //     cout<<m<<" ";
        // }
        // cout<<mp.size();
        return (mp.size()==pow(2,k));
    }
};