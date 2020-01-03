class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        unordered_map<int, int> num_count;
        int repeated = 0;
        bool found = false;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(found == false)
            {
                auto itr = num_count.find(nums[i]);
                if(itr == num_count.end())
                    num_count[nums[i]] = 1;
                else{
                    repeated = nums[i];
                    found = true;
                }
            }

        }
        
        int original = -1*sum + repeated + (nums.size()*(nums.size()+1))/2;
        vector<int> result;
        result.push_back(repeated);
        result.push_back(original);
        
        return result;
        
    }
};
