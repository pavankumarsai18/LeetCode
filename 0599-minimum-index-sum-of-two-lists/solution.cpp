class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        unordered_map<string, int> A;
        unordered_map<int, int> B;
        
        // //
        for(int i = 0; i < list1.size(); i++)
        {
            A[list1[i]] = i;
        }
        
        int min_sum = list1.size() + list2.size();
        
        for(int i = 0; i < list2.size(); i++)
        {
            auto itr = A.find(list2[i]);
            if(itr != A.end())
            {
                if(min_sum > i + itr->second)
                    min_sum = i + itr->second;
                B[i] = i+itr->second;
            }
       
        }
        
        vector<string> result;
        for(auto itr = B.begin(); itr != B.end(); itr++)
        {
            if(itr->second == min_sum)
                result.push_back(list2[itr->first]);
        }
        return result;
        
        
    }
};
