class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) 
    {
        const int maxVal = 1000;
        const int maxWeight = 5000;
        vector<int> counts(maxVal+1, 0);
        
        for(int i = 0; i < weight.size();i++)
        {
            counts[weight[i]]++;
        }
        
        int result = 0;
        int curWeight = 0;
        
        for(int i = 1; i < counts.size();i++)
        {
            if(counts[i] == 0) 
                continue;
            int take = min(counts[i], (maxWeight - curWeight)/i);
            
            if(take == 0)
                break;
    
            
            result += take;
            curWeight += take* i;
        }
        
        return result;
        
    }
};
