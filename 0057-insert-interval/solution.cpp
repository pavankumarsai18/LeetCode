class Solution {
public:
    bool intersects(vector<int>& interval, const int start, const int end)
    {
        // Case 1 start is between interval-start and interval end
        // ----
        //   ----
        bool startsAfter = (interval[0] <= start) && (interval[1] <= end) && (start <= interval[1]);
        // if(startsAfter)
        //     cout<<"startsAfter\n";
        
        // Case 2 newInterval is sandwiched b/n interval
        //  ----
        //   --
        bool sandwiched = (interval[0] <= start) && (end <= interval[1]);
        // if(sandwiched)
        //     cout<<"sandwiched\n";
        
        
        // Case 3 old interval is sandwiched by newInterval 
        //. --
        // -----
        bool subset = (start <= interval[0]) && (interval[1] <= end); 
        // if(subset)
        //     cout<<"subset\n";
        
        
        //Case 4 newInterval intersects the beginning of oldinterval
        //   -----
        // ----
        bool startsBefore = (start <= interval[0]) && (end <= interval[1]) && (interval[0] <= end);
        // if(startsBefore)
        //     cout<<"startsBefore\n";
        return (startsAfter || sandwiched || subset || startsBefore);

    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> mergedIntervals;
        
        const int n     = intervals.size();
        const int start = newInterval[0];
        const int end   = newInterval[1];
        // insert in end
        if(n == 0 || intervals[n-1][1] < newInterval[0])
        {
            vector<vector<int>> result = intervals;
            result.push_back(newInterval);
            return result;
        }
        // insert in beginning
        if(newInterval[1] < intervals[0][0])
        {
            vector<vector<int>> result = {newInterval};
            for(auto & interval: intervals)          
                result.push_back(interval);
            return result;
            
        }
        
        // insert in middle
        bool intersectsOnce = false;
        for(int i = 0; i < n; i++)
        {
            if(intersects(intervals[i], start, end))
            {
                intersectsOnce = true;
                break;
            }
        }
        // If it intersects
        if(intersectsOnce)
        {
            for(int i = 0; i < n; i++)
            {
                if(i < n && intersects(intervals[i], start, end))
                {
                    int newStart = std::min(intervals[i][0], start);
                    int newEnd   =  std::max(end, intervals[i][1]);

                    while(i+1 < n && intersects(intervals[i+1], start, end))
                    {
                        newEnd = std::max(newEnd, intervals[i+1][1]);
                        i++;
                    }
                    // cout<<"end index "<<i<<endl;
                    mergedIntervals.push_back({newStart, newEnd});   
                }
                else if(i < n)
                {
                    mergedIntervals.push_back(intervals[i]);
                }   
            }
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                mergedIntervals.push_back(intervals[i]);
                if(intervals[i][1] < start && end < intervals[i+1][0])
                {
                    mergedIntervals.push_back(newInterval);
                }
            }
        }
        
        
        
        return mergedIntervals;
    }
};
