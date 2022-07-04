// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    long long MOD=pow(10,9)+7;
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        long long first=1,second=1,third=2;
        // your code here
        if(n==1)
        return second;
        if(n==2)
        return third;
        long long ans=0;
        for(int i=3;i<=n;i++)
        {
            ans=(first%MOD+second%MOD+third%MOD)%MOD;
            first=second;
            second=third;
            third=ans;
        }
        return ans;
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