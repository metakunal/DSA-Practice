// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    long long MOD=1000000007;
    public:
    //Function to count the number of ways in which frog can reach the top.
    // vector<int> dp;
    long long helper(int n,vector<long long> &dp)
    {
         if(dp[n]!=-1)
        return dp[n]%MOD;
        if(n==0 ||n==1)
        return 1;
        if(n==2)
        return n;
       
        return dp[n]=(helper(n-1,dp)%MOD+helper(n-2,dp)%MOD+helper(n-3,dp)%MOD)%MOD;
        
    }
    long long countWays(int n)
    {
        vector<long long> dp(n+1,-1);
        // dp.resize(n);
        // for(int i=0;i<n;i++)
            // dp[i]=-1;
        // dp[0]=0;
        return helper(n,dp);
        // your code here
        
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends