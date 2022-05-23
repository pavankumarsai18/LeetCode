class Solution {
public:
    int expandAroundCenter(string & s, int mid1, int mid2)
    {
        int numPalindromes = 0;
        int l, r;
        l = mid1; 
        r = mid2;
        
        while(l >= 0 && r < s.size())
        {
            if(s[l] != s[r])
            {
                break;
            }
            l--;
            r++;
            numPalindromes++;
        }
        return numPalindromes;
    }
    int countSubstrings(string s) 
    {
        int palindromes = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            // Odd length palindrome
            // Then the middle values are the same
            palindromes += expandAroundCenter(s, i, i);
            
            // even length palindrome
            // The middle values are different
            palindromes += expandAroundCenter(s, i, i+1);
        }
        
        return palindromes;
        
    }
};
