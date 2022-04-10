class Solution {
public:
    int countLetters(string s) 
    {
        int result = 0;
        
        int index = 0;
        while(index < s.size())
        {
            int startIndex = index;
            char curChar = s[index];
            while(index < s.size() && curChar == s[index])
                index++;
            
            int len = index - startIndex;
            len = len*len+len;
            len >>= 1;
            result += len;
        }
        
        return result;
        
    }
};
