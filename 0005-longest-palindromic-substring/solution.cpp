class Solution {
private:
    void expandAroundCenter(string & s, int mid1, int mid2,  int & L, int & R)
    {
        int left, right;
        left = mid1; right = mid2;
        
        const int length = s.size();
        
        while(left >= 0 && right < length)
        {
            if(s[left] != s[right])
                break;
            
            left--; right++;
        }
        
        int lengthOfPalindrome = right - (left + 1);
        int lenLargestPalindrome = R - (L+1);
        if(lenLargestPalindrome < lengthOfPalindrome)
        {
            L = left;
            R = right;
        }
        
        return;
        
    }
public:
    string longestPalindrome(string s) 
    {
        string result = "";
        int L, R;
        L = R = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            // Odd length mid will be the same
            expandAroundCenter(s, i,i, L, R);
            
            // Even length mid will be different
            expandAroundCenter(s, i, i+1, L, R);
        }
        
        for(int i = L+1; i < R; i++)
            result += s[i];
        
        return result;
        
    }
};
