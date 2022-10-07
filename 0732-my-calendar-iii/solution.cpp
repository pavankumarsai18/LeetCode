class MyCalendarThree {
private:
    map<int, int> starts;
    int ans;
public:
    MyCalendarThree() {
        starts[0] = starts[1e9 + 1] = 0;
        ans = 0;
    }
    
    int book(int start, int end) 
    {
        starts[start] = (--starts.upper_bound(start))->second;
        starts[end]   = (--starts.upper_bound(end))->second;
        
        for(auto it = starts.find(start); it->first < end; it++)
        {
            ans = max(ans, ++(it->second));
        }
        return ans;   
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
