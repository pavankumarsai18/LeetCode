class MyCalendar {
private:
    set<pair<int, int>> meetings;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> newEvent = {start, end};

        auto nextEvent = meetings.lower_bound(newEvent);

        if (nextEvent != meetings.end() && nextEvent->first < end) {
            return false;
        } 

        if (nextEvent != meetings.begin()) {
            const auto prevEvent = prev(nextEvent);
            if (prevEvent->second > start) {
                return false;
            }
        }

        meetings.insert(newEvent);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
