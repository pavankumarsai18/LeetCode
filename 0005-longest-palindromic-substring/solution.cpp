class Solution {
public:
    void expandAroundCenter(string & s, int mid1, int mid2, int & L, int & R, int & maxLength)
    {
        if(mid1 >= s.size() || mid2 >= s.size())
            return;
        
        int l, r;
        l = mid1; r = mid2;
        
        while(l >= 0 && r <= s.size())
        {
            if(s[l] != s[r])
            {
                break;
            }
            l--; r++;

        }
        int length = r-l-1;
        if(length > maxLength)
        {
            maxLength = length;
            L = l+1;
            R = r-1;
        }
        
        
        return;
            
    }
    string longestPalindrome(string s) 
    {
        string ans = "";
        int L, R, maxLength;
        L=R=maxLength = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            expandAroundCenter(s, i, i, L, R, maxLength);
            if(i+1 < s.size() && s[i] == s[i+1])
                expandAroundCenter(s, i, i+1, L, R, maxLength);
        }
        
        return s.substr(L, maxLength);
    }
};
