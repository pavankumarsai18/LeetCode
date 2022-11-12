class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> secondHalf;
    priority_queue<int> firstHalf;
public:
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        int size = firstHalf.size() + secondHalf.size();
        
        firstHalf.push(num);
        
        if(secondHalf.size() && firstHalf.top() > secondHalf.top())
        {
            secondHalf.push(firstHalf.top());
            firstHalf.pop();
        }
            
        
        if(firstHalf.size() > secondHalf.size() + 1)
        {
            secondHalf.push(firstHalf.top());
            firstHalf.pop();
        }
        else if(secondHalf.size() > firstHalf.size() + 1)
        {
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        }
        
    }
    
    double findMedian() 
    {
        if(firstHalf.size() > secondHalf.size())
            return firstHalf.top();
        else if(secondHalf.size() > firstHalf.size())
            return secondHalf.top();
        
        return (firstHalf.top() + secondHalf.top())/2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
