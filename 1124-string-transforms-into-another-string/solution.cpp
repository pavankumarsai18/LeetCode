class Solution {
public:
    bool canConvert(string str1, string str2) 
    {
        if(str1 == str2) return true;
        
        
        vector<int> conversionMappings(26, ' ');
        vector<bool> str2Chars(26, false);
        int numUniqueInStr2 = 0;

        int ind1, ind2;
        for(int i = 0; i < str1.size(); i++)
        {
            ind1 = str1[i] - 'a';
            ind2 = str2[i] - 'a';
            
            if(conversionMappings[ind1] == ' ')
            {
                conversionMappings[ind1] = ind2;
                
                if(!str2Chars[ind2])
                {
                    numUniqueInStr2++;
                    str2Chars[ind2] = true;
                }
                
            }
            else if(conversionMappings[ind1] != ind2)
                return false;
        }
        
        if(numUniqueInStr2 < 26) return true;
        return false;
        
        
    }
};
