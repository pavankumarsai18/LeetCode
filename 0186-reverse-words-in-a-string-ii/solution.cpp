class Solution {
public:
    void reverseWords(vector<char>& s) 
    {
        const int len = s.size();
        for(int i = 0; i < len/2;i++)
        {
            std::swap(s[i], s[len-1 -i]);
        }
        
        int i = 0;
        while(i < s.size())
        {
            while(i < s.size() && s[i] == ' ')
            {
                i++;
            }
            
            int start = i;
            while(i < len && s[i] != ' '){i++;}
            int end = i - 1;
            while(start < end)
            {
                std::swap(s[start++], s[end--]);
            }
        }
        
        return;
        
    }
};
