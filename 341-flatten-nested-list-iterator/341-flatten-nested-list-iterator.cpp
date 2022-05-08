/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> flattenList;
    int current = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        //Creating a flattened list, by using recursion
        for(auto v:nestedList)
        {
            helper(v);
        }
    }
    //We are maintaing a current pointer to keep track of curr element
    int next() {
        return flattenList[current++];
    }
    
    bool hasNext() {
        return current<flattenList.size();
    }
    //Helper function to flatten the list
    //Here we traverse the list and if the element is an integer we push it to our flattened list, but if it is an Nestedlist we again call the helper function recursively.
    void helper(NestedInteger value)
    {
        if(value.isInteger()){
         flattenList.push_back(value.getInteger());   
        }else{
             for(auto v:value.getList())
        {
            helper(v);
        }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */