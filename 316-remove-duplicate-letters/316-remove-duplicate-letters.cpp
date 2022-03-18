class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26);
        vector<bool> visited(26);
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            last[s[i]-'a']=i;
        }
        for(int i=0;i<s.length();i++)
        {
            if(visited[s[i]-'a'])
                continue;
            
            while(!ans.empty() && ans.back()>s[i] && last[ans.back()-'a']>i)
            {
                visited[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            visited[s[i]-'a']=true;
        }
        return ans;
    }
};