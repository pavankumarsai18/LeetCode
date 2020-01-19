class Solution {
public:
    string freqAlphabets(string s) {
        
        string res = "";
        if(s.size() == 0)
            return res;
        
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == '#')
            {
                int temp = (static_cast<int>(s[i - 2]) - 48)*10 + static_cast<int>(s[i - 1]) - 48;
                res += static_cast<char>(temp + 96);
                i -= 2;
            }
            else
            {
                int temp = static_cast<int>(s[i]) - 48;
                res += static_cast<char>(temp + 96);
            }
        }
        
        for(int i = 0; i < res.size()/2; i++)
        {
            swap(res[i], res[res.size() - 1 - i]);
        }
        return res;

    }
};
