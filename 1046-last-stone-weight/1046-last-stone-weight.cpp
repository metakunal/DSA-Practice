class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> temp;
        for(auto s :stones)
        {
            temp.push(s);
        }
        while(temp.size()>=2)
        {
            int y = temp.top();
            temp.pop();
            int x = temp.top();
            temp.pop();
            if(x==y)
                continue;
            else
            {
                temp.push(y-x);
            }
        }
        int ans;
        if(temp.empty())
        {
            return 0;
        }
        else
        {
            ans = temp.top();
        }
        return ans;
    }
};