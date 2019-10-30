class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        map<char, int> char_count;
        for(int i = 0; i < text.size(); i++)
        {
            auto itr = char_count.find(text[i]);
            if(itr == char_count.end())
                char_count[text[i]] = 1;
            else
                char_count[text[i]] += 1;
        }
        char arr[] = {'b','a','l','o','n'}; 
        
        char_count['l'] /= 2;
        char_count['o'] /= 2;
        int min = -1;
        for(int i = 0; i < 5; i++)
        {
            if(min == -1)
                min = char_count['b'];
            
            else if(min > char_count[arr[i]])
                min = char_count[arr[i]];
        }
        
        return min;
    }
};
