// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// class Solution
// {
//   public:
//     long long minTime(int arr[], int n, int k)
//     {
//         // code here
//         // return minimum time
//     }
// };
class Solution
{
  public:
   bool isValid(int arr[],int n,int k,long long mid){
      
     long long int c_painters=1;
      long long int sum=0;
       for(int i=0;i<n;i++){
           //Extra addedCode
           if(arr[i]>mid)
           return false;
           sum+=arr[i];
           if(sum>mid){
               c_painters++;
               sum=arr[i];
           }
      if(c_painters>k){
           return false;
       }
       }
       
       return true;
       
   }
    long long minTime(int arr[], int n, int k)
    {
     long long int sum=0;
     long long int res=-1;
     long long int mx=INT_MIN;
      for(int i=0;i<n;i++){
          if(arr[i]>=mx){
              mx=arr[i];
          }
          sum+=arr[i];
      }
      
     long long int low=0;///??????
    long long  int high=sum;
    // if(k==n)
    //   {
    //       return low;
    //   }
      while(low<=high){
        long long int mid=low+(high-low)/2; 
          
         if(isValid(arr,n,k,mid)){
             res=mid;
             high=mid-1;
         }
          
         else{
             low=mid+1;
         }
          
          
      }
      return res;
      
        // code here
        // return minimum time
    }
};
// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends