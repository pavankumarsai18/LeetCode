#include <iterator>
#include <map>

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        int result = 0;
    
        for(int j = 0; j < words.size(); j++)
        {
            // cout<< words[j] << endl;
            
            // create a map
            map<char, int> char_map;
            for(int i = 0; i < chars.length(); i++)
            {
                char_map[chars[i]] = 0;
            }
            for(int i = 0; i < chars.length(); i++)
            {
                char_map[chars[i]] += 1;
            }
            
            bool is_in = true;
            
            for(int k = 0; k < words[j].length(); k++)
            {
                //find the element in the map
                if(char_map.find(words[j][k]) != char_map.end())
                {
                    if(char_map[words[j][k]] > 0)
                        char_map[words[j][k]] -= 1;    
                    else
                    {
                        is_in = false;
                        break;
                    }
                }
                
                else
                {
                    is_in = false;
                    break;
                }
                
            }
            // cout<< is_in<<endl;
            if(is_in)
            {
                result += words[j].length();
            }
        }
        
        return result;

    }
};
