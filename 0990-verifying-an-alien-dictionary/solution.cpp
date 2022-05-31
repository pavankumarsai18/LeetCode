class Solution {
public:
    bool isIncreasing(string & word1, string & word2, vector<int> & charPriority)
    {
        int index;
        index =  0;
        int minLength = min(word1.size(), word2.size());
        
        int index1, index2;

        while(index < minLength)
        {
            index1 = word1[index]-'a'; index2 = word2[index]-'a';
            
            
            if(charPriority[index1] > charPriority[index2])
                return false;
            if(charPriority[index1] < charPriority[index2])
                return true;
            index++;
        }
        
        return (word1.size() <= word2.size());
    
    }
    bool isAlienSorted(vector<string>& words, string order) 
    {
        
        vector<int> charPriority(26, 0);
        for(int i = 0; i < order.size(); i++)
        {
            charPriority[order[i]-'a'] = i;
        }
        
        for(int i = 0; i < words.size()-1; i++)
        {
            if(!isIncreasing(words[i], words[i+1], charPriority))
            {
                return false;
            }
        }
        
        return true;
        
    }
};
