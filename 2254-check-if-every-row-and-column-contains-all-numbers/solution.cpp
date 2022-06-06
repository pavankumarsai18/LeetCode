class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) 
    {
        auto n = matrix.size();
        
        for(auto i = decltype(n){0}; i < n; i++)
        {
            auto row_cache = std::bitset<101>{};
            auto col_cache = std::bitset<101>{};
            
            for(auto j = decltype(n){0}; j < n; j++)
            {
                row_cache.set(matrix[i][j]);
                col_cache.set(matrix[j][i]);
            }
            
            if(std::min(row_cache.count(), col_cache.count()) < n)
                return false;
        }
        
        
        
        
        return true;
        
        
        
    }
};
