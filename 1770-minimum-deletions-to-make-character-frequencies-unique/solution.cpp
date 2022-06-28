class Solution {
public:
    int minDeletions(string s) 
    {
        const int size = 26;
        
        int charCount[size];
        for(int i = 0; i < size; i++)
            charCount[i] = 0;
        
        for(int i = 0; i < s.size(); i++)
            charCount[s[i]-'a']++;
        
        
        sort(charCount, charCount + size, greater<int>());
        
        int allowedFrequency = s.size();
        int numDeletions     = 0;
        
        for(int i = 0; i < size && charCount[i] > 0; i++)
        {
            if(charCount[i] > allowedFrequency)
            {
                numDeletions += charCount[i] - allowedFrequency;
                charCount[i]  = allowedFrequency;
            }
            allowedFrequency = max(0, charCount[i] - 1);
        }
        
        return numDeletions;
        
    }
};
