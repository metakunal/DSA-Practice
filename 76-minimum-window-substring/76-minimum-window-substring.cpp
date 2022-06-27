class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        for(auto c:t)
        {
            mp[c]++;
        }
        int count=mp.size();
        int ans=INT_MAX;
        string res="";
        int i=0,j=0;
        int start=0,end=0;
        while(j<s.length())
    {
      // CALCULATION STEP ( As Aditya's general format)

       if(mp.find(s[j])!=mp.end())
       {
           mp[s[j]]--;
           if(mp[s[j]]==0)
           count--;
       }

// step to slide " j "

       if(count>0)
       j++;

// step where we will find a candidate for answer

       else if(count==0)
       {
           if(ans>j-i+1)
           {
               ans=j-i+1;
               end=j;
               start=i;
           }
            // A candidate for our Answer

// trying to minimize the window size after getting a candidate for answer

           while(count==0)
           {
               if(mp.find(s[i])==mp.end())
               {
                   i++;
                   if(ans>j-i+1)
           {
               ans=j-i+1;
               end=j;
               start=i;
           }
               }
               else
               {
                   mp[s[i]]++;
                   if(mp[s[i]]>0)
                   {
                       i++;
                       count++;
                   }
                   else
                   {
                       i++;
                        if(ans>j-i+1)
           {
               ans=j-i+1;
               end=j;
               start=i;
           }   // updating the answer
                   }
               }
           }
           j++;
       }
    }
    // cout<<ans<<endl;
        if(ans!=INT_MAX)
        {
           for(int i=start;i<=end;i++)
            res+=s[i]; 
        }
        
        return res;
    }
};