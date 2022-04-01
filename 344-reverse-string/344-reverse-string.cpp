class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=s.size();
        for(int i=0;i<s.size()/2;i++)
        {
            swap(s[i],s[l-i-1]);
        }
    }
};