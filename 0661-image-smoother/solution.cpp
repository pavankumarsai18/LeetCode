class Solution {
private:
    bool check(const vector<vector<int>>& M, int  r,int c) const
    {
        if( 0 <= r && r < M.size() && 0 <= c && c < M[0].size())
            return true;
        return false;    
    }
           
    int find_avg(vector<vector<int>>& M, int row, int col) const
    {

        double sum = 0;
        int num = 0;
        
        
        for(int i = row - 1; i <= row + 1; i++)
        {
            for(int j = col - 1; j <= col + 1; j++)
            {
                if(check(M, i, j))
                {

                    sum += M[i][j];
                    num++;
                }
            }
        }
        return floor(sum*1.0/num);
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M)
    {
        vector<vector<int>> result;
        for(int i = 0; i < M.size(); i++)
        {
            vector<int> temp;
            for(int j = 0; j < M[i].size(); j++)
            {
                int r = find_avg(M, i, j);
                temp.push_back(r);
            }
            
            result.push_back(temp);
        }
        return result;
        
        
    }
};
