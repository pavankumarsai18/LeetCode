class Solution {
public:
    string reverseVowels(string s) 
    {
        
        vector<int> vInd;
        
        for(int i = 0; i < s.size(); i++)
        {
            auto c = tolower(s[i]); 
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                vInd.push_back(i);
            }
        }
        
        if(vInd.size() > 0)
        {
            for(int i = 0; i < vInd.size()/2; i++)
            {
                swap(s[vInd[i]], s[vInd[ vInd.size() - i - 1]]);
            }
        }
        
        return s;        
    }
};
