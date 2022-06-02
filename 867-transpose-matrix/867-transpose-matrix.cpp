class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        vector<vector<int>> res(C, vector<int>(R, 0));
     for(int i=0;i<R;i++)
     {
         for(int j=0;j<C;j++)
         {
             res[j][i]=matrix[i][j];
         }
     }
        return res;
    }
};