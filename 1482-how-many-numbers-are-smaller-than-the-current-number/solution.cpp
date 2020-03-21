class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        // O(nlgn)
        if(nums.size() == 0)
            return vector<int>();
        
        auto copy = nums;
    
        
        sort(nums.begin(), nums.end());

        unordered_map<int, int> S;
        for(int i = 0; i < nums.size(); i++)
        {
            auto itr = S.find(nums[i]);
            if(itr == S.end())
                S[nums[i]] = i;
        }
        
        vector<int> result;
        for(int i = 0; i < copy.size(); i++)
        {
            result.push_back(S[copy[i]]);
        }
        return result;
        
        
        
    }
};
