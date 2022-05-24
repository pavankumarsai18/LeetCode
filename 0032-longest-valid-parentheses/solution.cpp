class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<int> S;

        unordered_set<int> erroneous;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
               
                S.push(i);
            }
            else
            {
                if(S.empty())
                {
                    erroneous.insert(i);
                }
                else
                {
                    S.pop();
                }
            }
        }
        while(S.size())
        {
            erroneous.insert(S.top());S.pop();
        }
        
        // for(auto & item: erroneous)
        //     cout<<item<<' ';
        // cout<<endl;
        int longestParen = 0;
        int curLen = 0;
        
        
        for(int i = 0; i < s.size(); i++)
        {
            if(erroneous.find(i) != erroneous.end())
            {
                longestParen = max(longestParen, curLen);
                curLen = 0;
                continue;
            }
            if(s[i] == ')')
            {
                curLen++;
                longestParen = max(longestParen, curLen);
            }
        }
        return longestParen*2;
        
    }
};
