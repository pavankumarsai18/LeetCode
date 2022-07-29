class Solution {
private:
    bool match(string & word, string & pattern)
    {
        unordered_map<char, char> word_pattern;
        for(int i = 0; i < word.size(); i++)
        {
            if(word_pattern.find(word[i]) == word_pattern.end())
            {
                word_pattern[word[i]] = pattern[i];
            }
            else if(word_pattern[word[i]] != pattern[i]) 
            {
                return false;
            }
        }
        return true;
    }
    
    bool wordMatchesPattern(string & word, string & pattern)
    {
        if(word.size() != pattern.size()) return false;
        return match(word, pattern) && match(pattern, word);
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> ans;
        for(int i = 0; i < words.size(); i++)
        {
            if(wordMatchesPattern(words[i], pattern)) ans.push_back(words[i]);
        }
        
        return ans;
    }
};
