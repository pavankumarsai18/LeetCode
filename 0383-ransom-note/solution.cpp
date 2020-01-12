class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        if(magazine.size() == 0 && ransomNote.size() == 0)
            return true;
        else if(magazine.size() == 0)
            return false;
        else if(ransomNote.size() == 0)
            return true;
        
        unordered_map<char, int> char_count;
        
        for(int i = 0; i < magazine.size(); i++)
        {
            auto itr = char_count.find(magazine[i]);
            if(itr == char_count.end())
            {
                char_count[magazine[i]] = 1;
            }
            else
            {
                char_count[magazine[i]]++;
            }
        }
        
        for(int i = 0; i < ransomNote.size(); i++)
        {
            auto itr = char_count.find(ransomNote[i]);
            if(itr == char_count.end())
                return false;
            if(itr->second > 0)
            {
                char_count[ransomNote[i]]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
