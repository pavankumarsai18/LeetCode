class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> seen;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int otherNum = target - nums[i];
            if(seen.find(otherNum) != seen.end())
            {
                return {seen[otherNum],i};
            }
            
            seen[nums[i]] = i;
        }
        
        return {};
        
    }
};
