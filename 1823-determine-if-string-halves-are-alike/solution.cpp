class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int firstHalf, secondHalf;
        firstHalf = secondHalf = 0;
        
        unordered_set<char> vowels;
        
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            {
                if(i < s.size()/2)
                {
                    firstHalf++;
                }
                else
                {
                    secondHalf++;   
                }
            }
        }
        
        return (firstHalf == secondHalf);
    }
};
