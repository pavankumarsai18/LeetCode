class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        auto cmp = [](vector<int> & a, vector<int> & b)
        {
            return a[1] < b[1];  
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
        for(int i = 0; i < boxTypes.size(); i++)
        {
            pq.push(boxTypes[i]);
        }
        
        
        int numUnits = 0;
        while(truckSize > 0 && !pq.empty())
        {
            vector<int> boxType = pq.top(); pq.pop();
            
            int numBoxes       = min(boxType[0], truckSize);
            int numUnitsPerBox = boxType[1];
            
            numUnits += numBoxes*numUnitsPerBox;
            truckSize -= numBoxes;
        }
        
        
        return numUnits;
    }
};
