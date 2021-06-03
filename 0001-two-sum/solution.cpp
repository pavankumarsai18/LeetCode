class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> num_count;
        unordered_map<int, vector<int>> num_indicies;
        for(int i = 0; i < nums.size(); i++)
        {
            auto itr = num_count.find(nums[i]);
            
            auto itr2 = num_indicies.find(nums[i]);
            if(itr == num_count.end())
            {
                num_count[nums[i]] = 1;
                
            }
            else if(itr != num_count.end()){
                num_count[nums[i]]++;
                
            }
            if(itr2 == num_indicies.end())
            {
                num_indicies[nums[i]] = vector<int>();
                (num_indicies[nums[i]]).push_back(i);
            }
            if(itr2 != num_indicies.end())
            {
                (num_indicies[nums[i]]).push_back(i);
            }
        }
        
        vector<int> result;
        
        for(auto itr = num_count.begin(); itr != num_count.end(); itr++)
        {
            int secondNumber = target - itr->first;
            
            auto secondItr = num_count.find(secondNumber);
            
            if(secondItr != num_count.end())
            {
                if(secondNumber == itr->first && itr->second >= 2)
                {
                    vector<int> indicies = num_indicies[secondNumber];
                    result.push_back(indicies[0]);
                    result.push_back(indicies[1]);
                    return result;
                }
                else if(secondNumber != itr->first)
                {
                    result.push_back((num_indicies[secondNumber])[0]);
                    result.push_back((num_indicies[itr->first])[0]);
                    return result;
                }
            }
        }
        
        return result;
        
    }
};
