class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        unordered_map<char,int> mp;
        int max=INT_MIN;
        char cmax;
        string res=s;
        for(auto c:s)
        {
            mp[c]++;
            if(mp[c]>max)
            {
                cmax=c;
                max=mp[c];
            }

        }
        if (max > (n + 1) / 2) {
            return ""; 
        }

        int i=0;
        while(mp[cmax])
        {
            res[i]=cmax;
            mp[cmax]--;
            i=i+2;
        }
         for (auto c: mp) {
            while (c.second > 0) {
                if (i >= n) i = 1; // First time it reaches L, reset it. Won't be inf loop cause not looping on idx
                res[i] = c.first;
                c.second=c.second-1;
                i += 2;
            }
        }
        return res;
    }
};