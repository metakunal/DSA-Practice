class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minheap.push(num);
        maxheap.push(minheap.top());
        minheap.pop();
        if(maxheap.size()>minheap.size())
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size()>maxheap.size())
            return minheap.top();
        else
        {
            return (minheap.top()+maxheap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */