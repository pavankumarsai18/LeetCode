class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> numberLetter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> result;
        
        for(int i = 0; i < digits.size(); i++)
        {
            int digitIndex = digits[i] - '0';
            vector<string> newWords;
            if(i == 0)
            {
                for(int k = 0; k < numberLetter[digitIndex].size(); k++)
                {
                    string newWord(1, numberLetter[digitIndex][k]);
                    
                    newWords.push_back(newWord);
                }
            }
            else
            {
                for(int k = 0; k < numberLetter[digitIndex].size(); k++)
                {
                    for(int j = 0; j < result.size(); j++)
                    {
                        string newWord = result[j] + numberLetter[digitIndex][k];
                        newWords.push_back(newWord);
                    }
                }
            }
            result = newWords;
        }
        
        return result;
        
    }
};
