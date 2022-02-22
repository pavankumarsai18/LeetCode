class Solution {
public:
    int titleToNumber(string columnTitle) 
    {
        int result = 0;
        
        for(int i = 0; i < columnTitle.size() - 1; i++)
        {
            result += (columnTitle[i]-64);
            result <<= 1;
            result *= 13;
        }
        result += (columnTitle[columnTitle.size() - 1]-64);
        return result;        
    }
};
