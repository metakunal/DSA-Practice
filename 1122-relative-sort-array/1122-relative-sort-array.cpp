class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto a:arr1)
        {
            mp[a]++;
        }
        vector<int> res;
        for(auto b:arr2)
        {
           if(mp.find(b)!=mp.end())
           {
                while(mp[b]--)
                    res.push_back(b);
               mp.erase(b);
           }
        }
        for(auto m:mp)
        {
            int b=m.second;
            while(b--)
                res.push_back(m.first);
            mp.erase(m.first);
        }
        return res;
    }
};