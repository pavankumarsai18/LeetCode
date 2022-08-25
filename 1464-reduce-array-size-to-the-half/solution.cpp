class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        unordered_map<int, int> numCount;
        for(int i = 0; i < arr.size(); i++)
        {
            numCount[arr[i]]++;
        }
        
        
        vector<int> counts;
        for(auto & [num, count]: numCount)
        {
            counts.push_back(count);
        }
        
        sort(counts.begin(), counts.end());
        
        int curIndex = counts.size() - 1;
        int numRemoved = 0;
        int minSet     = 0;
        
        while(numRemoved < arr.size()/2)
        {
            
            numRemoved += counts[curIndex];
            curIndex--;
            minSet++;
        }
        
        
        return minSet;
        
        
        
        
        
    }
};
