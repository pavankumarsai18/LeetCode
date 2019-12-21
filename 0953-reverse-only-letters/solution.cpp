class Solution {
public:
    string reverseOnlyLetters(string S) 
    {
        unordered_map<int, char> index_char;
        
        string letters = "";
        for(int i = 0; i < S.size(); i++)
        {
            if((S[i] >= 'a' && S[i] <= 'z' ) || (S[i] >= 'A' && S[i] <= 'Z'))
            {
                letters += S[i];
            }
            else
            {
                index_char[i]  = S[i];
            }
        }
        
        for(int i = 0; i < letters.size()/2; i++)
        {
            std::swap(letters[i],letters[letters.size() - 1 - i]);
        }
        
        string result = "";
        int index = 0;
        for(int i = 0; i < S.size(); i++)
        {
            auto itr = index_char.find(i);
            if(itr == index_char.end())
            {
                result += letters[index];
                index++;
            }
            else
            {
                result += index_char[i];
            }
        }
        
        return result;   
    }
};
