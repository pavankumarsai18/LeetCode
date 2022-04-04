class Solution {
public:
    int calculateTime(string keyboard, string word) 
    {
        unordered_map<char, int> map;
        
        for(int i = 0; i < keyboard.size(); i++)
        {
            map[keyboard[i]] = i;
        }
        
        int timeTaken = 0;
        int curIndex = 0;
        for(int i = 0; i < word.size(); i++)
        {
            timeTaken += abs(map[word[i]] - curIndex);
            curIndex = map[word[i]];
        }
        return timeTaken;
    }
};
