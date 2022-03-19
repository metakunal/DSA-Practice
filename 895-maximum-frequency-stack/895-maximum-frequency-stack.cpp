class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> m;
    int maxFreq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq,freq[val]);
        m[freq[val]].push(val);
    }
    
    int pop() {
        //Getting our answer as the element that is at the top of our maximum frequency stack
        int ans = m[maxFreq].top();
        m[maxFreq].pop();
        
        //Decreasing the current the current frequency of our answer element 
        freq[ans]--;
        
        //If the stack size corresponding to maximum frequency becomes 0, then we decrease the maximum frequency.
        if(m[maxFreq].size()==0)
        {
            maxFreq--;
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */