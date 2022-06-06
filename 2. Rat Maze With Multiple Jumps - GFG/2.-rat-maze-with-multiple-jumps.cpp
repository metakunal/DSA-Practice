// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void print(int n, vector<int> sol[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends



//Function to find the minimum number of Hops required for the rat to 
//reach from the source block to the destination block. 
bool isSafe(vector<int> maze[],int n, int i,int j){
   if(i<n && j<n && maze[i][j]>0){
       return true;
   }
   return false;
}


bool goTo(vector<int> maze[],int n,int i,int j,vector<int> result[]){
   if(i==n-1 && j==n-1){
       result[i][j]=1;
       return true;
   };
   if(isSafe(maze,n,i,j)){
       result[i][j]=1;
       int mxjumps=maze[i][j];
       for(int k=1;k<=mxjumps;k++){
           if(j!=n-1 && goTo(maze,n,i,j+k,result)==true){
               return true;
           }
           if(i!=n-1 && goTo(maze,n,i+k,j,result)==true){
               return true;
           }
       }
       //if all jumps fail backtrack
       result[i][j]=0;
       return false;
   }
   else{
       return false;
   }
   return false;
}


//Function to find the minimum number of Hops required for the rat to 
//reach from the source block to the destination block. 
void solve(int n, vector<int> maze[]) 
{
   vector<int> result[n];
   for(int i=0;i<n;i++){
       result[i].assign(n,0);
   }
   if(goTo(maze,n,0,0,result)==true)
   {
       print(n,result);
       return;
   }
   cout<<"-1\n";
   return;
}