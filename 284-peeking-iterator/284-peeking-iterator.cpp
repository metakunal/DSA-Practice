/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    int top;
    vector<int> numsc;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    top = 0;
        numsc = nums;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return numsc[top];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int ele = numsc[top];
        top++;
        return ele;
	}
	
	bool hasNext() const {
        // cout<<top;
        cout<<numsc.size()-1;
	    if(numsc.size()-1 >= top)
            return true;
        else
            return false;
	}
};