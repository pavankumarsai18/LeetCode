class Solution {
private:
    stack<char> parseString(const string & s)
    {
        stack<char> Stack;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i]== '#' && Stack.size())
            {
                Stack.pop();
            }
            else if(s[i] != '#')
            {
                Stack.push(s[i]);
            }
        }
        return Stack;
    }
public:

    bool backspaceCompare(string s, string t) 
    {
        stack<char> sStack = parseString(s);
        stack<char> tStack = parseString(t);
    
        while(sStack.size() && tStack.size())
        {
            if(sStack.top() != tStack.top())
                return false;
            
            sStack.pop(); tStack.pop();
        }
        
        return (sStack.size() == 0 && tStack.size() == 0);
       
    }
};
