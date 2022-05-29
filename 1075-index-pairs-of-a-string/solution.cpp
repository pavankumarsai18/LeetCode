class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) 
    {
        unordered_set<char> word_starting_char;
        unordered_map<char, int> char_max_length;
        unordered_set<string> wordSet;
        
        for(auto & word:words)
        {
            wordSet.insert(word);
            word_starting_char.insert(word[0]);
            char_max_length[word[0]] = max(char_max_length[word[0]], int(word.size()));
        }
        
//         for(auto & item: word_starting_char)
//         {
//             cout<<item<<" ";
//         }cout<<endl;
        
//         for(auto & [ch, len]:char_max_length)
//             cout<<ch<<" "<<len<<endl;
        
        
        vector<vector<int>> result;
        
        for(int i = 0; i < text.size(); i++)
        {
            if(word_starting_char.find(text[i]) != word_starting_char.end())
            {
                string match_string = "";
                int j = i;
                int max_length = char_max_length[text[i]];
                while(j < text.size() && (j-i) < max_length)
                {
                    match_string += text[j];
                    if(wordSet.find(match_string) != wordSet.end())
                    {
                        // cout<<i<<" "<<j<<endl;
                        result.push_back({i,j});
                    }
                    j++;
                }
            }
        }
        
        return result;
    }
};
