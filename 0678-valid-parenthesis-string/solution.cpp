class Solution {
public:
    void print(stack<int> S)
    {
        cout<<S.size()<<endl;
    }
    bool checkValidString(string s) {

        stack<int> parenStack;
        stack<int> stars;
        int numstars = 0;
        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i] == '*')
            {
                stars.push(i);
            }
            else if(s[i] == '(')
                parenStack.push(i);
            else
            {
                if(parenStack.size() > 0)
                {
                    parenStack.pop();
                }
                else if(stars.size() > 0)
                {
                    stars.pop();
                }
                else
                {
                    return false;
                }
            }
            // print(parenStack);

        }
        if(stars.size() < parenStack.size())
            return false;
        
        while(stars.size() && parenStack.size())
        {
            if(stars.top() > parenStack.top())
            {
                stars.pop();
                parenStack.pop();
            }
            else
            {
                return false;
            }
            
        }
        
        return true;
    }
};
