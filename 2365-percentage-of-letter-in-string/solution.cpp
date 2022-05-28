class Solution {
public:
    int percentageLetter(string s, char letter) 
    {
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(letter == s[i])
                count++;
        }

        return (int)(count*100.0)/(s.size()*1.0);
        
    }
};
