#include <algorithm>
class Solution {
public:
    int maxProduct(vector<string>& words) 
    {

        
        int product = 0;
        const int length = words.size();
        
        vector<int> bitWords;
        
        for(auto & word: words)
        {
           int bitWord = 0;
            for(int i = 0; i <word.size(); i++)
            {
                bitWord |= 1<<(word[i] - 'a');
            } 
            bitWords.push_back(bitWord);
        }
        

        for(int i = 0; i < length; i++)
        {
            for(int j = i+1; j < length; j++)
            {
                if((bitWords[i]&bitWords[j]) == 0)
                {
                    product = max(product, int(words[i].size()*words[j].size()));
                }
            }
        }
        
        return product;
        
    }
};
