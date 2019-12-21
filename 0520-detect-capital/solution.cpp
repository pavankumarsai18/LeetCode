class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        int cap_count = 0;
        
        for(int i = 0; i < word.size();i++)
        {
            if(word[i] >= 'A' && word[i] <= 'Z')
                cap_count++;
        }
        if(cap_count == 0 || cap_count == word.size())
            return true;
        else if(cap_count == 1)
            if(word[0] >= 'A' && word[0] <= 'Z')
                return true;
        return false;
        
    }
};
