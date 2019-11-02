class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        string result = "";
        while(i < s.size())
        {
            string temp = "";
            while(i< s.size() && s[i] != ' ')
            {
                temp += s[i];
                i++;
            }
            
            for(int j = 0; j < temp.size()/2; j++)
            {
                char temp_ = temp[j];
                temp[j] = temp[temp.size() - 1 - j];
                temp[temp.size() - 1 - j] = temp_;
            }
            result += temp;
            if(i < s.size() - 1)
                result += " ";   
            i++;
        }
        
        return result;
    }
};
