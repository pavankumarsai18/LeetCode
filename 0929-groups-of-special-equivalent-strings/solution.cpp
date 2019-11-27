class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) 
    {
        set< pair<multiset<char>, multiset<char> > > result;
        
        for(int i = 0; i < A.size(); i++)
        {
            multiset<char> a;
            multiset<char> b;
            for(int j = 0; j < A[i].size(); j++)
            {
                if(j%2 == 0)
                    a.insert(A[i][j]);
                else
                    b.insert(A[i][j]);
            }
            pair<multiset<char>, multiset<char>> p;
            p.first = a;
            p.second = b;
            result.insert(p);
        }
        
        return result.size();
    }
    
    
};
