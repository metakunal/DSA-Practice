class Solution {
public:
    int area(vector<vector<int>>& grid,int r,int c,vector<vector<bool>> &visited)
    {
        if(r<0||r>=grid.size()||c<0||c>=grid[0].size()||visited[r][c]||grid[r][c]==0)
        {
                        return 0;
        }
            visited[r][c]=true;
            return (1+area(grid,r-1,c,visited)+area(grid,r+1,c,visited)+area(grid,r,c-1,visited)+area(grid,r,c+1,visited));
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    ans=max(ans,area(grid,i,j,visited));
            }
        }
        return ans;
    }
};