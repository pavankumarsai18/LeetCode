class MedianFinder {
private:
    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<int>> larger;
public:
    MedianFinder() 
    {
        smaller = priority_queue<int>();
        larger  = priority_queue<int, vector<int>, greater<int>>();
    }
    
    void addNum(int num) 
    {
        smaller.push(num);
        
        if(smaller.size() && larger.size() && smaller.top() > larger.top())
        {
            larger.push(smaller.top());
            smaller.pop();
        }
        
        if(smaller.size() > larger.size() + 1)
        {
            larger.push(smaller.top());
            smaller.pop();
        }
        else if(larger.size() > smaller.size() + 1)
        {
            smaller.push(larger.top());
            larger.pop();
        }
        
    }
    
    double findMedian() 
    {
        if(smaller.size() > larger.size())
            return smaller.top();
        else if(larger.size() > smaller.size())
            return larger.top();
        
        return (smaller.top() + larger.top())/2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
