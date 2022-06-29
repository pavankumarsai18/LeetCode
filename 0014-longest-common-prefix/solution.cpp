class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string result = strs[0];
        
        for(int i = 1; i < strs.size(); i++)
        {
            bool matched = true;
            for(int j = 0; j < strs[i].size(); j++)
            {
                if(result[j] != strs[i][j])
                {
                    matched = false;
                    result = result.substr(0, j);
                    break;
                }
            }
            
            if(matched)
            {
                result = result.substr(0, strs[i].size());
            }
        }
        return result;
        
    }
};
