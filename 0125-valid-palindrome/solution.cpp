class Solution {
public:
    bool isPalindrome(string s) 
    {
        string alpha_n= "";
        
        for(int i = 0; i < s.size(); i++)
        {
            if(isalnum(s[i]))
                alpha_n += tolower(s[i]);
        }
        
        string r_a_n = alpha_n;
        for(int i = 0; i < r_a_n.size()/2; i++)
        {
            std::swap(r_a_n[i], r_a_n[r_a_n.size() - 1 - i]);
        }
        if(r_a_n == alpha_n)
            return true;
        return false;
    }
};
