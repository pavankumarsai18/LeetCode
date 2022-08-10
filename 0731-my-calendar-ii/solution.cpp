class MyCalendarTwo {
private:
    map<int, int> calendar;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) 
    {
        int events = 0;
        auto itr = calendar.begin();
        
        while(itr != calendar.end() && itr->first < end)
        {
            events += itr->second;
            itr++;
            
            if(itr->first > start && events > 1) return false;
        }
        
        calendar[start]++;
        calendar[end]--;
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
