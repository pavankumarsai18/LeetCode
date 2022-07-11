class Solution {
public:
    vector<vector<int>> twoSum(vector<int> & nums, int excludedIndex, int target)
    {
        vector<vector<int>> ans;
        int lo = excludedIndex + 1;
        int hi = nums.size() - 1;
        int sum;
        while(lo < hi)
        {
            sum = nums[lo] + nums[hi];
            if(sum > target)
                hi--;
            else if(sum < target)
                lo++;
            else
            {
                ans.push_back({nums[lo], nums[hi]});
                lo++;
                hi--;
                while(lo < hi && nums[lo] == nums[lo - 1])
                {
                    lo++;
                }
            }
            
        }
        
        return ans;
        
    }
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        unordered_set<int> seen;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0) break;
            
            if(i == 0 || nums[i-1] != nums[i])
            {
                int target = -nums[i];
                for(auto & pos: twoSum(nums,i, target))
                {
                    pos.push_back(nums[i]);
                    ans.push_back(pos);
                }
            }
        }
        return ans;
    }
};
