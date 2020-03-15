class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        if(nums.size() == 0)
            return false;
        if(k > nums.size())
            k = nums.size();
        
//         for(int i = 0; i < nums.size() - k; i++)
//         {
//             unordered_map<int, int> M;
//             for(int j = 0; j < k; j++)
//             {
//                 auto itr = M.find(nums[i + j]);
//                 if(itr == M.end())
//                 {
//                     M[nums[i+j]] = 0;
//                 }
//                 else
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
        
        unordered_map<int, vector<int>> M;
        for(int i = 0; i < nums.size(); i++)
        {
            auto itr = M.find(nums[i]);
            if(itr == M.end())
            {
                vector<int> temp = {i};
                M[nums[i]] = temp;
            }
            else
            {
                M[nums[i]].push_back(i);
            }    
        }
        
        for(auto itr = M.begin();itr != M.end(); itr++)
        {
            if(itr->second.size() > 1)
            {
                for(int i = 0; i < itr->second.size() - 1; i++)
                {
                    if( (itr->second)[i+1] - (itr->second)[i] <= k)
                        return true;
                }
            }
        }
        return false;
    }
};
