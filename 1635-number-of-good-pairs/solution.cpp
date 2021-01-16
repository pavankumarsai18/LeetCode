class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int, int> num_count;
        
        for(auto & num: nums)
        {
            auto itr = num_count.find(num);
            
            if(itr == num_count.end())
            {
                num_count[num] = 0;
            }
            num_count[num]++;
        }
        
        int result = 0;
        
        for(auto itr = num_count.begin(); itr != num_count.end(); itr++)
        {
            result += ((itr->second - 1)*(itr->second))/2;
        }
        
        return result;
        
    }
};
