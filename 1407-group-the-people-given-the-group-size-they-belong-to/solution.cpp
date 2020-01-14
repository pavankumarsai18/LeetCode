class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        unordered_map<int, vector<int>> num_index;
        vector<vector<int>> result;
        
        for(int i = 0; i < groupSizes.size(); i++)
        {
            auto itr = num_index.find(groupSizes[i]);
            if(itr == num_index.end())
            {
                vector<int> index;
                index.push_back(i);
                num_index[groupSizes[i]] = index;
                
                if(groupSizes[i] == 1)
                {
                    auto temp = num_index[groupSizes[i]];
                    result.push_back(temp);
                    vector<int> e;
                    num_index[groupSizes[i]] = e;
                }
                
            }
            else
            {
                auto temp = num_index[groupSizes[i]];
                temp.push_back(i);
                
                if(temp.size() == groupSizes[i])
                {
                    result.push_back(temp);
                    vector<int> e;
                    num_index[groupSizes[i]] = e;
                    
                }
                else
                {
                    num_index[groupSizes[i]] = temp;
                }
            }       
        }
        
        return result;
    }
};
