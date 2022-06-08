// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isSafe(int grid[N][N],int row,int col,int num)
    {
        for (int d = 0; d < 9; d++)  
        { 
            
            if (grid[row][d] == num) { 
                return false; 
            } 
        } 
  
        for (int r = 0; r < 9; r++)  
        { 
               
            if (grid[r][col] == num)  
            { 
                return false; 
            } 
        }  
        int s = (int)sqrt(N); 
        int boxRowStart = row - row % s; 
        int boxColStart = col - col % s; 
  
        for (int r = boxRowStart; 
             r < boxRowStart + s; r++)  
        { 
            for (int d = boxColStart; 
                 d < boxColStart + s; d++)  
            { 
                if (grid[r][d] == num)  
                { 
                    return false; 
                } 
            } 
        } 
  
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
      int row = -1; 
        int col = -1; 
        bool isEmpty = true; 
        for (int i = 0; i < 9; i++)  
        { 
            for (int j = 0; j < 9; j++)  
            { 
                if (grid[i][j] == 0)  
                { 
                    row = i; 
                    col = j; 
                    isEmpty = false; 
                    break; 
                } 
            } 
            if (!isEmpty) { 
                break; 
            } 
        } 
  
        if (isEmpty)  
        { 
            return true; 
        } 
        
        for (int num = 1; num <= 9; num++)  
        { 
            if (isSafe(grid, row, col, num))  
            { 
                grid[row][col] = num; 
                if (SolveSudoku(grid))  
                { 
                    // print(board, n); 
                    return true; 
                } 
                else 
                { 
                    grid[row][col] = 0; 
                } 
            } 
        } 
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }

        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends