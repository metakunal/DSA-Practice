class Solution {
public:
    bool isValid(vector<int>& position, int m,int dist)
    {
        int n=position.size();
        int lastPlaced=position[0];
        int count=1;
        for(int i=0;i<n;i++)
        {
            if(position[i]-lastPlaced>=dist)
            {
                count++;
                lastPlaced = position[i];
            }
        }
        return (count>=m);
    }
    int maxDistance(vector<int>& position, int m) {
        int low=1;
        sort(position.begin(),position.end());
        int high=position.back();
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(isValid(position,m,mid))
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return high;
    }
};