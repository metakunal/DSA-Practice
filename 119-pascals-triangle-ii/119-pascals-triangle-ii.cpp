class Solution {
public:
    vector<int> getRow(int numRows) {
        numRows=numRows+1;
          vector<vector<int>> res(numRows);
        if(numRows>=1)
            res[0].push_back(1);
        if(numRows>=2)
        {
            res[1].push_back(1);
            res[1].push_back(1);
        }
        for(int i=2;i<numRows;i++)
        {
            res[i].push_back(1);
            for(int j=0;j<i-1;j++)
            {
                res[i].push_back(res[i-1][j]+res[i-1][j+1]);
            }
            res[i].push_back(1);
        }
        return res[numRows-1];
    }
};