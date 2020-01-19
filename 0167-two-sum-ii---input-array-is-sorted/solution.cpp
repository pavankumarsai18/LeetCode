class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        
        unordered_map<int, int> num_count;
        for(int i = 0; i < numbers.size(); i++)
        {
            auto itr = num_count.find(numbers[i]);
            if(itr == num_count.end())
                num_count[numbers[i]] = i;
        }
        
        
        for(int i = 0; i < numbers.size(); i++)
        {
            if(target - numbers[i] == numbers[i])
            {
                if(i > 0 && numbers[i-1] == numbers[i])
                {
                    vector<int> res;
                    res.push_back(i);
                    res.push_back(i + 1);
                    return res;
                }
                else if( i < numbers.size() - 1 && numbers[i] == numbers[i + 1])
                {
                    vector<int> res;
                    res.push_back(i + 1);
                    res.push_back(i + 2);
                    return res;
                }
            }
            else
            {
                auto itr = num_count.find(target - numbers[i]);

                if(itr != num_count.end())
                {
                    if(itr->second > i)
                    {
                        vector<int> result;
                        result.push_back(i + 1);
                        result.push_back(itr->second + 1);
                        return result;
                    }
                }
            }
        }
        return vector<int>();
        
        
        
    }
};
