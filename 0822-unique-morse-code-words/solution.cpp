#include <set>

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        set <string> result;
        string alpha_morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(int i = 0; i < words.size(); i++)
        {
            string morse = "";
            for(int j = 0; j < words[i].length(); j++)
            {
                morse += alpha_morse[static_cast<int>((words[i])[j]) - 97];
            }
            
            result.insert(morse);
        }
        
        return result.size();
    }
};
