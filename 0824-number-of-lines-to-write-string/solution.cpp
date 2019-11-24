class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S)
    {
        if(S.size() == 0)
        {
            vector<int>temp  = {0, 0};
            return temp;
        }
        vector<int> result;
        
        const int max_char = 100;
        int len_sum = 0;
        int num_lines = 1;
        for(int i = 0; i < S.size(); i++)
        {
            len_sum += widths[static_cast<int>(S[i]) - 97];
         
            if(len_sum >= max_char)
            {
                num_lines++;
                if(len_sum > max_char)
                    len_sum = widths[static_cast<int>(S[i]) - 97];
                else
                    len_sum = 0;
            }
        }
        
        result.push_back(num_lines);
        result.push_back(len_sum);
        return result;
        
    }
};
