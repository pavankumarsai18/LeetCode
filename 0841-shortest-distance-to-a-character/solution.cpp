class Solution {
public:
    vector<int> shortestToChar(string S, char C) 
    {
        vector<int> index_C;
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == C)
                index_C.push_back(i);
        }
        
        
        vector<int> result;
        for(int i = 0; i < index_C[0];i++)
        {
            result.push_back(index_C[0] - i);
        }
        
        
        int i, j;
        i = 0;
        j = 1;
        
        for(int k = index_C[0]; k < index_C[index_C.size() - 1]; k++)
        {
            int x = abs(k - index_C[i]);
            int y = abs(k - index_C[j]);
            if(x < y)
                result.push_back(x);
            else
                result.push_back(y);
            
            if(k == index_C[j])
            {
                i++;
                j++;
            }
        }

        for(int i = index_C[index_C.size() - 1]; i < S.size(); i++)
        {
            result.push_back(i- index_C[index_C.size() - 1]);
        }
        return result;
        
    }
};
