// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  vector<vector<int>> dp;
    int sum;
    
    int fun(int total,vector<int> v,int tar,int i)
    {
        if(i<0)
        {
            if(total-(sum-total)==tar)
                return 1;
            
            return 0;
        }
        
        if(dp[i][total]!=-1)
            return dp[i][total];
        
        if(total-v[i]>=0)
        return dp[i][total] = fun(total-v[i],v,tar,i-1) + fun(total,v,tar,i-1);
        
        else
            return dp[i][total] = fun(total,v,tar,i-1);
    }
    
    int findTargetSumWays(vector<int>& v, int tar) 
    {
        int total = 0;
        int n = v.size();
        
        for(int i=0;i<v.size();i++)
            total+=v[i];
        
        sum = total;
        
        dp.clear();
        dp.resize(n+1,vector<int> (total+1,-1));
        
        return fun(total,v,tar,n-1);
    }
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends