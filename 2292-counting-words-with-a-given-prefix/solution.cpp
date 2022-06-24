class Solution {
public:
    int prefixCount(vector<string>& words, string pref) 
    {
        int numPrefix = 0;
        const int prefixSize = pref.size();
        for(int indx = 0; indx < words.size(); indx++)
        {
    
    if(words[indx].size() >= prefixSize && words[indx].substr(0,prefixSize) == pref)
            {
                numPrefix++;
            }
        }
        
        return numPrefix;
        
    }
};
