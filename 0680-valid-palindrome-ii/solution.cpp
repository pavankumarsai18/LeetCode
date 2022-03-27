class Solution {
private:
    bool isPalindrome(const string & s)
    {
        for(int i = 0 ; i < s.size()/2; i++)
        {
            if(s[i] != s[s.size() -1 - i])
                return false;
        }
        return true;
    }
    
    bool isPalindrome(const string & s, const int& index)
    {
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j)
        {
            if(i == index)
            {
                i++;
                continue;
            }
            if(j == index)
            {
                j--;
                continue;
            }
            if(i != index || j != index)
            {
                if(s[i] != s[j])
                    return false;
            }
            
            i++;
            j--;

        }
        return true;
    }
public:
    bool validPalindrome(string s) 
    {
        
        if(isPalindrome(s))
            return true;
        
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return (isPalindrome(s, i) || isPalindrome(s, j));
            }
            i++;j--;
        }
        
        return true;
    }
};
