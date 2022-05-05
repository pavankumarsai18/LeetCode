class Solution {
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        unordered_map<int, int> numCount;
        
        for(int i = 0; i < nums.size(); i++)
        {
            numCount[nums[i]]++;
        }
        
        int result = 0;
        
        for(auto itr = numCount.begin(); itr != numCount.end(); itr++)
        {
            int target = k - itr->first;
            
            if(numCount.find(target) != numCount.end())
            {
                int targetCount = numCount[target];
                if(target == itr->first && targetCount >= 2)
                {
                    result += (numCount[target])/2;
                    numCount[target] %= 2;
                    continue;
                }
                else if(target != itr->first && targetCount > 0 && itr->second > 0)
                {
                    int minCount = min(targetCount, itr->second);
                    result += minCount;
                    numCount[target] -= minCount;
                    numCount[itr->first] -= minCount;
                }
            }
        }
        
        return result;
        
    }
};
