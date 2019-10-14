class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char> is_matched;
        vector<int> stack_empty;
        
        char start_char = s[0];
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == start_char)
            {
                is_matched.push(start_char);
            }
            else
            {
                is_matched.pop();
            }
            if(is_matched.empty())
            {
                stack_empty.push_back(i);
                start_char = s[i+1];
            }    
        }
        
        return stack_empty.size();
    }
};
