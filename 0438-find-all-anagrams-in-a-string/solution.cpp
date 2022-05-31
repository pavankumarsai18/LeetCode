class Solution {
public:
    bool isAnagram(vector<int> & anagram, vector<int>& substring)
    {
        for(int i = 0; i < anagram.size();i++)
        {
            if(anagram[i] != substring[i])
                return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string text, string anagram) 
    {
        const int num_letters = 26;
        const int anagram_size = anagram.size();
        const int text_size    = text.size();
        
        if(text_size < anagram_size)
            return vector<int>();
        
        vector<int> result;
        
        vector<int> anagram_chars(num_letters, 0);
        
        vector<int> text_anagram(num_letters, 0);
        
        for(int i = 0; i < anagram.size(); i++)
        {
            anagram_chars[anagram[i]-'a']++;
        }
        
        int index = 0;
        while(index < anagram_size)
        {
            text_anagram[text[index]-'a']++;
            index++;
        }
        index--;
        if(isAnagram(anagram_chars, text_anagram))
            result.push_back(index-anagram_size + 1);
        
        while(index + 1 < text_size)
        {
            index++;
            

            text_anagram[text[index-anagram_size]-'a']--;
            text_anagram[text[index]-'a']++;
            
            if(isAnagram(anagram_chars, text_anagram))
                result.push_back(index-anagram_size + 1);
            
        }
        return result;
    }
};
