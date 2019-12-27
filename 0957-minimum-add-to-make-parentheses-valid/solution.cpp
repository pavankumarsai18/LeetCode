class Solution {
public:
    int minAddToMakeValid(string S)
    {
        stack<char> par_left;
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == '(')
            {
                par_left.push(S[i]);
            }
            else
            {
                if(par_left.size() != 0 && par_left.top() == '(' )
                {
                    par_left.pop();
                }
                else
                {
                    par_left.push(')');
                }

            }
        }

        return par_left.size();
        
    }
};
