class Solution {
public:
    vector<vector<int>> memo;
    int total;
    int findTargetSumWays(vector<int>& v, int target) {
        total=accumulate(v.begin(),v.end(),0);
        int n=v.size();
        memo.clear();
        memo.resize(n+1,vector<int> (2*total+1,-1));

        return fun(v,0,0,target);
    }
    int fun(vector<int> v,int i,int sum,int tar)
    {
        if(i==v.size())
        {
            if(sum==tar){
                return 1;
            }else{
                return 0;
            }
        }else{
            if (memo[i][sum + total] != -1) {
                return memo[i][sum + total];
            }
            int add = fun(v, i + 1, sum + v[i], tar);
            int subtract = fun(v, i + 1, sum - v[i], tar);
            memo[i][sum + total] = add + subtract;
            return memo[i][sum + total];
        }
    }
};