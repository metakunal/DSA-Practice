class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
     vector<pair<int, int>> mp;
        
        for(int i=0;i<mat.size();i++)
        {int sum=0;
            for(auto b:mat[i])
            {
                sum+=b;
            }
         cout<<sum<<" ";
           mp.push_back(make_pair(sum,i));
        }
        vector<int> res;
        sort(mp.begin(),mp.end());
        for(int i=0;i<k;i++)
        {
            res.push_back(mp[i].second);
        }
        return res;
    }
};