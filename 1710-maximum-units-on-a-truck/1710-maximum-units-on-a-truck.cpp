class Solution {
public:
    static bool cmp(vector<int> &v1,vector<int> &v2)
    {
        if(v1[1]==v2[1])
            return v1[0]>v2[0];
        else
            return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0;
        for(auto b:boxTypes)
        {
            if(truckSize>=b[0])
            {
                ans+=b[0]*b[1];
                truckSize-=b[0];
            }
            else
            {
              ans+=truckSize*b[1] ; 
                truckSize=0;
            }
            if(truckSize<=0)
                break;
            
        }
        return ans;
       
    }
};