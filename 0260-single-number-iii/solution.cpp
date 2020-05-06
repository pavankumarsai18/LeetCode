class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
     
        unordered_map<int, int> M;
        
        for(int i = 0; i < nums.size(); i++)
        {
            auto itr = M.find(nums[i]);
            if(itr == M.end())
            {
                M[nums[i]] = 1;
            }
            else
            {
                M[nums[i]]++;
            }
        }
        
        vector<int> result;
        for(auto itr = M.begin(); itr != M.end(); itr++)
        {
            if(itr->second == 1)
            {
                result.push_back(itr->first);
            }
        }
        
        return result;
    }
};
