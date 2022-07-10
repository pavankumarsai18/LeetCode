class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> seen;
        int num;
        for(int i = 0; i < nums.size(); i++)
        {
            num = nums[i];
            auto itr = seen.find(target - num);
            if(itr != seen.end())
            {
                return {itr->second, i};
            }
            
            seen[num] = i;
        }
        
        return {};
        
    }
};
