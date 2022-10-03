class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        int pos = startFuel;
        int numStops = 0;
        const int n = stations.size();
        
        priority_queue<int> pq;
        int i = 0;
        while(pos < target)
        {
            while(i < n && pos >= stations[i][0])
            {
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty()) return -1;
            
            pos += pq.top(); pq.pop();
            
            numStops++;
        }
        
        
        return numStops;
        
        
        
    }
};
