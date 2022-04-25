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
private:
    Iterator curItr, nextItr;
    int nextVal;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), curItr(nums), nextItr(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        nextVal = -1;
        
        if(nextItr.hasNext())
        {
            nextVal = nextItr.next();
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() 
    {
        return nextVal;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() 
    {
        int result = -1;
        if(curItr.hasNext())
        {
            result = curItr.next();
            if(nextItr.hasNext())
            {
                nextVal = nextItr.next();
            }
            else
            {
                nextVal = -1;
            }
        
        }
	    return result;
	}
	
	bool hasNext() const 
    {
        return curItr.hasNext();
	}
};
