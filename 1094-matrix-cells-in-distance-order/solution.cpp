class Solution 
{
public:
    
    int dist(const int& x, const int& y, const int& x0, const int& y0)
    {
        return abs(x - x0) + abs(y - y0);
    }
    
    static bool cmp(const pair<const int, vector<int>>& a, const pair<const int, vector<int>>& b) 
    {
      return a.first < b.first; 
    }
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {   
        vector<vector<int>> result;
       
        vector<std::pair<int, vector<int>>> s;
        for(int i = 0;i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                int d = dist(i, j, r0, c0);
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                s.push_back(pair<int, vector<int>>(d, temp) );
            }
        }
        
        sort( s.begin(), s.end(), cmp);
        for(auto itr = s.begin(); itr !=  s.end(); itr++)
        {
            result.push_back(itr->second);
        }
        return result;
    }
};
