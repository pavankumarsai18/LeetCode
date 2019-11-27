class Solution {
public:
    bool is_vowel(char s)
    {
        s = tolower(s);
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
            return true;
        return false;
    }
    
    string toGoatLatin(string S) 
    {
        string result = "";
        
        int num_words = 0;
    
        for(int i = 0; i < S.size(); i++)
        {
            string temp = "";
            while(i < S.size() && S[i] != ' ')
            {
                temp += S[i];
                i++;
            }
            num_words += 1;
            
            if(is_vowel(temp[0]))
            {
                temp += "ma";
                for(int j = 0; j < num_words; j++)
                    temp += "a";
                
                result += temp;
                if(i != S.size())
                    result += " ";
            }
            else
            {
                string temp_ = "";
                for(int K = 1; K < temp.size(); K++)
                {
                    temp_ += temp[K];
                }
                temp_ += temp[0];
                
                temp_ += "ma";
                
                for(int j = 0; j < num_words; j++)
                    temp_ += "a";
                
                result += temp_;
                if(i != S.size())
                    result += " ";
            }
            
        }
        
        return result;
        
    }
};
