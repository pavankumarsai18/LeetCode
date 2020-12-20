class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> Matcher;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                Matcher.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if(Matcher.size() == 0)
                {
                    return false;
                }
                
                if(s[i] == ')' && Matcher.top() == '(')
                {
                    Matcher.pop();
                }
                else if(s[i] == ']' && Matcher.top() == '[')
                {
                    Matcher.pop();
                }
                else if(s[i] == '}' && Matcher.top() == '{')
                {
                    Matcher.pop();
                }
                else{
                    return false;
                }
            }
            
        }
        
        return Matcher.empty();
        
    }
};
