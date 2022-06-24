class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numCount;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(numCount.find(target-nums[i]) != numCount.end())
            {
                ans = {i, numCount[target-nums[i]]};
                return ans;
            }
            numCount[nums[i]] = i;
                   
        }
        return ans;
        
    }
};
