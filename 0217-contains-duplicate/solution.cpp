class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int, int> numCount;
        for(int i = 0; i < nums.size(); i++)
        {
            numCount[nums[i]]++;
        }
        return numCount.size() != nums.size();
        
    }
};
