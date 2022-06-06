class Solution {
public:
    vector<int> countBits(int n) 
    {
        if(n == 0)
        {
            return {0};
        }
        
        vector<int> result = {0,1};
        
        while(result.size() < (n+1))
        {
            int curSize = result.size();
            int i       = 0;
            while(i < curSize && result.size() < (n+1))
            {
                result.push_back(result[i] + 1);
                i++;
            }
        }
        return result;
    }
};
