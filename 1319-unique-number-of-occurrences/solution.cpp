class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int, int> num_count;
        for(size_t i = 0; i < arr.size(); i++)
        {
            auto itr = num_count.find(arr[i]);
            if(itr == num_count.end())
            {
                num_count[arr[i]] = 1;
            }
            else
            {
                num_count[arr[i]] += 1;
            }
        }
        
        map<int, int> count_count;
        for(auto itr = num_count.begin(); itr != num_count.end(); itr++)
        {
            auto itr_ = count_count.find(itr->second);
            if(itr_ == count_count.end())
            {
                count_count[itr->second] = 1;
            }
            else
            {
                count_count[itr->second] += 1;   
            }
            
        }
        
        //
        for(auto itr = count_count.begin(); itr != count_count.end(); itr++)
        {
            if(itr->second > 1)
                return false;
        }
        
        return true;
    }
};
