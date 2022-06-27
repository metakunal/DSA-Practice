class Solution {
public:
    bool isPossible(vector<int>& target) {
     priority_queue<long long> pq;
    long long sum=0;
        for(auto ele:target)
        {
            pq.push(ele);
            sum+=ele;
        }
        cout<<sum<<" ";
        while(pq.top()!=1)
        {
            int t=pq.top();
            pq.pop();
            sum=sum-t;
            if(sum<=0 || sum>=t)
                return false;
            t=t%sum;
            sum=sum+t;
            pq.push(t>0?t:sum);
        }
        return true;
    }
};