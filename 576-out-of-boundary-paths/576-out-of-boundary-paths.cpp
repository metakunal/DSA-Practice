class Solution {
public:
    int M = 1000000007;
    int solve(int r,int c,int m,int n,int maxMove,vector<vector<vector<int>>> &dp)
    {
        if(r<0||r==m||c<0||c==n)
            return 1;
        if(maxMove==0)
            return 0;
        if(dp[r][c][maxMove]!=-1)
            return dp[r][c][maxMove];
          long long up=solve(r-1,c,m,n,maxMove-1,dp);
        long long down=solve(r+1,c,m,n,maxMove-1,dp);
        long long left=solve(r,c-1,m,n,maxMove-1,dp);
        long long right=solve(r,c+1,m,n,maxMove-1,dp);
        return dp[r][c][maxMove]= (up+down+left+right)%1000000007;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp (m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return solve(startRow,startColumn,m,n,maxMove,dp);
    }
};