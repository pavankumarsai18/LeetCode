class Solution {
public:
    string removeOuterParentheses(string S) 
    {
        stack<char> is_matched;
        vector<int> is_finished;
        int i = 0;
        is_finished.push_back(0);
        for(i; i < S.size(); i++)
        {
            if(S[i] == '(')
            {    is_matched.push(S[i]);}
            else
            {   is_matched.pop();}
            if(is_matched.empty())
            {
                is_finished.push_back(i);
                is_finished.push_back(i+1);
            }
            
        }
        
        is_finished.push_back(S.size() - 1);
        
        
        string result  = "";
        int j = 0;
        for(i = 0; i < S.size(); i++)
        {
            if( j < is_finished.size() && i == is_finished[j])
            {
                j++;
            }
            else
            {
                 result += S[i];
            }
                
        }
        return result;
    }
};
