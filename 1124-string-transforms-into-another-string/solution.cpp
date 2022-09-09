class Solution {
public:
    bool canConvert(string str1, string str2) 
    {
        if(str1 == str2) return true;
        
        vector<bool> uniqueChars(26, false);
        int numUnique = 0;
        vector<char>map(26, '-');
        
        for(int i = 0; i < str1.size(); i++)
        {
            int ind1 = str1[i] - 'a';
            int ind2 = str2[i] - 'a';
            
            if(map[ind1] == '-')
            {
                map[ind1] = str2[i];
            }
            else if(map[ind1] != str2[i])
            {
                return false;
            }
            
            if(!uniqueChars[ind2])
            {
                numUnique++;
                uniqueChars[ind2] = true;
            }
        }
        
        if(numUnique < 26) return true;
        return false;
    }
};
