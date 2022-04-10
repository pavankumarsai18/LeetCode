class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) 
    {
        unordered_set<int> S;
        for(int i = 0; i < mat.size();i++)
        {
            unordered_set<int>S2;
            for(int j = 0; j < mat[0].size(); j++)
            {
                if(i == 0)
                {
                    S.insert(mat[i][j]);
                }
                if(S.find(mat[i][j]) != S.end())
                    S2.insert(mat[i][j]);
            }
            
            if(S2.size() < S.size())
            {
                S = S2;
            }
        }
        if(S.size() == 0)
            return -1;
        int result = *S.begin();
        for(auto itr = S.begin(); itr!=S.end(); itr++)
        {
            result = min(result, *itr); 
        }
        return result;
        
    }
};
