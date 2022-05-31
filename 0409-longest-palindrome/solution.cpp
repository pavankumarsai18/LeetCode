class Solution {
public:
    int longestPalindrome(string s) 
    {
        vector<int> charCount(128, 0);
        
        for(int i=0;i <s.size(); i++)
        {
            charCount[s[i]]++;
        }
        
        int maxLength = 0;
        bool noOddExists = true;
        
        for(int i = 0; i < charCount.size();i++)
        {
            int count = charCount[i];
            if(noOddExists && count&1)
                noOddExists = false;
            count>>=1; count<<=1;
            
            maxLength += count;
        }
        
        return noOddExists?maxLength:maxLength+1;
    }
};
