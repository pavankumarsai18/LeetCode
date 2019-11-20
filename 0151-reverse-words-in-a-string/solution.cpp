class Solution {
public:
    string reverseWords(string s) 
    {
        vector<string> reverse;
        
        for(int i = 0; i < s.size(); i++)
        {
            string temp = "";
            while(i < s.size() && s[i] != ' ')
            {
                temp += s[i];
                i++;
            }
            if(temp != "")
                reverse.push_back(temp);
        }
        
        string result = "";
        for(int i = reverse.size() - 1; i >= 0; i--)
        {
            result += reverse[i];
            if(i != 0)
                result += " ";
        }
        return result;
        
    }
};
