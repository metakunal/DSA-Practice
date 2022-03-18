class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26);
        vector<bool> visited(26);
        string ans="";
        //Storing the last index of every character in a vector
        for(int i=0;i<s.length();i++)
        {
            last[s[i]-'a']=i;
        }
        for(int i=0;i<s.length();i++)
        {
            //If already visited then skip
            if(visited[s[i]-'a'])
                continue;
            
            //Here we check if the character at end of answer is greater than current character
            //and also we have occurences of that character after i
            //then we pop it from the answer and mark its visited as false
            while(!ans.empty() && ans.back()>s[i] && last[ans.back()-'a']>i)
            {
                visited[ans.back()-'a']=false;
                ans.pop_back();
            }
            //Push S[i] to ans and mark its visited as true.
            ans.push_back(s[i]);
            visited[s[i]-'a']=true;
        }
        return ans;
    }
};