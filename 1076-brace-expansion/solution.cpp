class Solution {
public:
    vector<string> expandIndexed(const string & s, int index)
    {
        if(index >= s.size()) return vector<string>();

        vector<string> result;
        string curString = "";
        int i = index;

        
        while(i < s.size() && s[i] != '{')
        {
            curString += s[i];
            i++;
        }
        if(i < s.size() && s[i] == '{')
        {
            i++;
        }
        
        vector<string> braceStrings;
        while(i < s.size() && s[i] != '}')
        {

            string braceString = "";
            while(i < s.size() && s[i] != ',')
            {
                if(s[i] == '}')
                {
                    break;
                }
                braceString += s[i];
                i++;
            }
            braceStrings.push_back(braceString);
            if(i < s.size() && s[i] == '}')
            {
                break;
            }
            i++;
        }
        // sort(braceStrings.begin(), braceStrings.end());
        
        if(i < s.size() && s[i] == '}'){i++;}
        
        vector<string> suffix = {""};
        if(i < s.size())
        {
            suffix = expandIndexed(s, i);
        }


        if(braceStrings.size() == 0 && suffix[0] == "")
        {
            result.push_back(curString);
            return result;
        }
        
        for(auto itr = braceStrings.begin(); itr != braceStrings.end(); itr++)
        {
            for(auto itr2 = suffix.begin(); itr2 != suffix.end(); itr2++)
            {
                result.push_back(curString + *itr + *itr2);
            }
        }
    
        return result;
    }
    vector<string> expand(string s) 
    {
        
        vector<string> result = expandIndexed(s, 0);
        sort(result.begin(), result.end());
        return result;
        
    }
};
