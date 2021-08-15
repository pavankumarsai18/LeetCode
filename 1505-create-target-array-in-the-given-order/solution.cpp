class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        
        vector<int> result;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            result.insert(result.begin() + index[i], nums[i]);
        }
        
        return result;
        
    }
};
