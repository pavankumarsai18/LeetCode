class Solution {
public:
    string licenseKeyFormatting(string s, int k) 
    {
        string nonDashChars = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '-')
            {
                nonDashChars += toupper(s[i]);
            }
        }
        
        const int length    = nonDashChars.size();
        int numGroups = length/k;
        int remainder = length%k;
        string ans = "";
        
        for(int i = 0; i < length;)
        {
            if(i != 0 || remainder == 0)
            {
                ans += nonDashChars.substr(i, k);
                i   += k;
                numGroups--;
                if(numGroups > 0)
                {
                    ans += '-';
                }
            }
            else if(remainder != 0)
            {
                ans += nonDashChars.substr(i, remainder);
                if(numGroups > 0)
                    ans += '-';
                i += remainder;
            }
        }
        
        return ans;
    }
};
