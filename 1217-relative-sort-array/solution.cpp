class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> num_count;
        for(int i = 0; i < arr1.size(); i++)
        {
            auto itr = num_count.find(arr1[i]);
            if(itr != num_count.end())
                num_count[arr1[i]] += 1;
            else
                num_count[arr1[i]] = 1;
        }
        
        vector<int> result;
        for(int i = 0; i < arr2.size(); i++)
        {
            for(int j = 0; j < num_count[arr2[i]];j++)
            {
                result.push_back(arr2[i]);
            }
            num_count[arr2[i]] = 0;
        }
        
        vector<int>temp;
        for(auto itr = num_count.begin(); itr != num_count.end(); itr++)
        {
            
            if(itr->second != 0)
            {
                for(int j = 0 ;j < num_count[itr->first]; j++)
                    temp.push_back(itr->first);
                num_count[itr->first] = 0;
            }
        }
        
        sort(temp.begin(), temp.end());
        
        for(int i = 0; i < temp.size(); i++)
        {
            
            result.push_back(temp[i]);
        }
        
        return result;
        
    }
};
