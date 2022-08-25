class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        const int numChars = 26;
        
        int magazineCharCount[numChars] = {0};
        int ransomCharCount[numChars] = {0};
        
        
        for(int i = 0; i < magazine.size(); i++)
        {
            magazineCharCount[magazine[i] - 'a']++;
        }
        
        for(int i = 0; i < ransomNote.size(); i++)
        {
            ransomCharCount[ransomNote[i] - 'a']++;
        }
        
        for(int i = 0; i < numChars; i++)
        {
            if(magazineCharCount[i] < ransomCharCount[i])
            {
                return false;
            }
        }
        
        return true;
        
        
        
        
    }
};
