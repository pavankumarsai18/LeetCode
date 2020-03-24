class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int, int> M;
        for(auto n: nums)
        {
            auto itr = M.find(n);
            if(itr == M.end())
                M[n] = 1;
            else
                M[n]++;
        }
        
        for(auto itr = M.begin(); itr != M.end(); itr++)
        {
            if(itr->second == 2 || itr->second == 1)
                return itr->first;
        }
        
        return -1;
        
        
        
    }
};
