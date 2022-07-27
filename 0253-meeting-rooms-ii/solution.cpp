class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        // min meeting rooms = max conficting rooms
        const int n = intervals.size();
        
        vector<int> startTimings(n, 0);
        vector<int> endTimings(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            startTimings[i] = intervals[i][0];
            endTimings[i]   = intervals[i][1];
        }
        
        sort(startTimings.begin(), startTimings.end());
        sort(endTimings.begin(), endTimings.end());
        
        
        int end, start; end = start = 0;
        int numRooms = 0;
        
        while(start < n)
        {
            if(startTimings[start] >= endTimings[end])
            {
                numRooms--; end++;
            }
            
            numRooms++;
            start++;
        }
        
        return numRooms;
    }
};
