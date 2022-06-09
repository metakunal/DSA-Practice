class Solution {
public:
    int removePalindromeSub(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        // cout<<rev<<" "<<s;
     if(s.length()==0)
         return 0;
     else if(rev==s)
        return 1;
     else
        return 2;
    }
};