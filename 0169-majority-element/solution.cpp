class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> num_count;
        for(int i = 0; i < nums.size(); i++)
        {
            num_count[nums[i]] = 0;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            num_count[nums[i]] ++;
        }
        
        auto itr = num_count.begin();
        while(itr != num_count.end())
        {
            if(itr->second >= (nums.size()/2 + 1))
            {
                return itr->first;
            }
            itr++;
        }
        return 0;
    }
};
