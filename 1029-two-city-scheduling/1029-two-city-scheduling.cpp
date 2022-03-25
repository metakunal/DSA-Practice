class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
     int n=costs.size();
        int cost=0;
        for(int i=0;i<n;i++)
        {
            cost+=costs[i][0];
        }
        vector<int> costb;
         for(int i=0;i<n;i++)
        {
            costb.push_back(costs[i][1]-costs[i][0]);
        }
        sort(costb.begin(),costb.end());
        for(int i=0;i<n/2;i++)
        {
            cost+=costb[i];
        }
        return cost;
    }
};