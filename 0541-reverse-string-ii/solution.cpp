class Solution {
public:
    void reverseStr(string & s, int start, int end)
    {
        while(start < end)
        {
            std::swap(s[start++], s[end--]);
        }
    }
    
    string reverseStr(string s, int k) 
    {
        int i = 0;
        
        while(i < s.length())
        {
            int remLen = s.length() - i - 1;
            int start = i;
            int end = k + start - 1;

            if(remLen >= 2*k)
            {
                reverseStr(s, start, end);
                i = k + i - 1 + k;
            }
            else if((remLen < 2*k && remLen >= k) || remLen < k)
            {
                if(remLen < k)
                {
                    end = s.length() - 1;
                }
                reverseStr(s, start, end);
                i = s.length() - 1;
                break;
            }
            else
            {
                break;
            }
            i++;
        }
        
        return s;
        
    }
};
