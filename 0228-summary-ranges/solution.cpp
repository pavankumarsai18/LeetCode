class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        
        if(nums.size() == 0)
        {
            return result;
        }
        else if(nums.size() == 1)
        {
            result.push_back(to_string(nums[0]));
            return result;
        }
        
        
        int cur_index = 0;
        
        while(cur_index < nums.size())
        {
            int start = cur_index;
            
            while(cur_index + 1 < nums.size() && nums[cur_index] + 1 == nums[cur_index + 1])
            {
                cur_index += 1;
            }
            
            if(cur_index < nums.size() && nums[start] == nums[cur_index])
            {
                result.push_back(to_string(nums[cur_index]));
                cur_index += 1;
                
            }
            else if(cur_index < nums.size() && nums[cur_index] - nums[start] >= 1 )
            {
                
                result.push_back(to_string(nums[start]) + "->" + to_string(nums[cur_index]));
                
                cur_index += 1;
            }
            
            
        }
        
        return result;
        
    }
};
