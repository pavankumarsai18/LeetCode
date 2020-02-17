class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        stack<int> S;
        vector<int> result;
        unordered_map<int, int> M;
        for(int i = 0; i < T.size(); i++)
        {
            if(S.empty())
            {
                S.push(i);
                M[i] = -1;
            }
            else
            {
                while(!S.empty() && T[S.top()] < T[i])
                {
                    M[S.top()] = i;
                    S.pop();
                }
                S.push(i);
                M[i] = -1;
            }
        }
        
        for(int i = 0; i < T.size(); i++)
        {
            if(M[i] == -1)
                result.push_back(0);
            else
                result.push_back(M[i] - i);
        }
        
        return result;
        
    }
};
