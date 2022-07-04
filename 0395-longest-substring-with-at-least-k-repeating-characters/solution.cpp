class Solution {
public:
    int longestSubstring(string text, int k) 
    {
        const int n = text.size();
        const int letters = 26;
        
        bool seen[letters] = {0};
        int maxUnique = 0;
        for(int i = 0; i < n; i++)
        {
            if(!seen[text[i]-'a']){
                seen[text[i]-'a'] = true;
                maxUnique++;
            }
        }
        
        int result = 0;
        int charCount[letters];
        for(int curUnique = 1; curUnique <= maxUnique; curUnique++)
        {
            memset(charCount, 0, sizeof(charCount));
            int left, right, idx, unique, countAtleastK;
            
            left = right = idx = unique = countAtleastK = 0;
            
            while(right < n)
            {
                if(unique <= curUnique)
                {
                    idx = text[right]-'a';
                    if(charCount[idx] == 0) unique++;
                    
                    charCount[idx]++;
                    if(charCount[idx] == k) countAtleastK++;
                    right++;
                }
                else
                {
                    idx = text[left]-'a';
                    if(charCount[idx] == k) countAtleastK--;
                    charCount[idx]--;
                    if(charCount[idx] == 0) unique--;
                    left++;
                }
                
                if(unique == curUnique && unique == countAtleastK)
                {
                    result = max(result, right-left);
                }
            }
        }
        return result;
    }
};
