class Solution {
public:
    bool backspaceCompare(string S, string T) 
    {
        // if(S.size() != T.size())
        //     return false;
        
        stack<char> s_stack;
        stack<char> t_stack;
        
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == '#')
            {
                if(!s_stack.empty())
                    s_stack.pop();
            }
            else
            {
                s_stack.push(S[i]);
                
            }
        }
        for(int i = 0; i < T.size(); i++)
        {
            if(T[i] == '#')
            {
                if(!t_stack.empty())
                    t_stack.pop();
            }
            else
                t_stack.push(T[i]);
        }
        
        if(s_stack.size() != t_stack.size())
            return false;
        
        while(!s_stack.empty())
        {
            if(s_stack.top() != t_stack.top())
                return false;
            s_stack.pop();
            t_stack.pop();
        }
        
        return true;
    }
};
