class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mp;
        for(auto c:s)
        {
            mp[c]++;
        }
        priority_queue<int> pq;
        for(auto m:mp)
        {
            pq.push(m.second);
        }
        int ans=0;
        while(pq.size()>1)
        {
            int t=pq.top();
            pq.pop();
            if(pq.top()==t)
            {
                t--;
                if(t>0)
                pq.push(t);
                                ans++;

            }
        }
        return ans;
    }
};