class Solution {
public:
    int numJewelsInStones(string J, string S) 
    {
        unordered_map<char, int> char_count;
        for(int i = 0; i < S.size(); i++)
        {
            auto itr = char_count.find(S[i]);
            if(itr == char_count.end())
            {
                char_count[S[i]] = 1;
            }
            else
            {
                char_count[S[i]]++;
            }
        }
        int sum = 0;
        for(int i = 0; i < J.size(); i++)
        {
            auto itr = char_count.find(J[i]);
            if(itr != char_count.end())
            {
                sum += char_count[J[i]];
            }
        }
        return sum;
        
    }
};
