class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.length();
        string empty="";
        for(int i=0;i<n/2;i++)
        {
            if(palindrome[i]!='a')
            {
                palindrome[i]='a';
            return palindrome;
            }
        }
        palindrome[n-1]='b';
        if(n<2)
        {
            return empty;
        }
        else
        {
            return palindrome;
        }
    }
};