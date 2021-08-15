class Solution {
public:
    int maxDepth(string s) 
    {
        
        int result = 0;
        
        stack<char> S;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                S.push('(');
            }
            else if(s[i] == ')')
            {
                S.pop();
            }
            
            if(result < S.size())
            {
                result = S.size();
            }
        }
        
        return result;
        
    }
};
