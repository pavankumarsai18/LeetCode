class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        auto one_number = 0;
        
        for(auto & num: nums)
        {
            one_number ^= num;
        }
        
        return one_number;
        
    }
};
