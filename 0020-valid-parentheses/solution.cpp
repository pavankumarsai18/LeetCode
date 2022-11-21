class Solution {
public:
    bool isValid(string input) 
    {
        stack<char> S;
        
        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] == '(' || input[i] == '{' || input[i] == '[')
            {
                S.push(input[i]);
            }
            else
            {
               
                if(S.empty()) return false;
            
                else if((input[i] == ')' && S.top() == '(') || (input[i] == ']' && S.top() == '[') || (input[i] == '}' && S.top() == '{'))
                {
                    S.pop();
                }
                else
                    return false;
            }
        }
        
        return S.empty();
        
    }
};
