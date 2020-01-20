class Solution {
private:
    int blocksum(vector<vector<int>>& row_sum, int i, int j , int k)
    {
        
        int s = 0;
        int min_y = max(0, i - k);
        int max_y = min( i+k, int(row_sum.size()) - 1);
        
        for(int y = min_y; y <= max_y; y++)
        {
            int max_x = min(j+k, int(row_sum[0].size()) - 1);
            int min_x = max(0, j - k);
            
            if(min_x != 0)
                s += row_sum[y][max_x] - row_sum[y][min_x - 1];
            else if(min_x == 0)
                s += row_sum[y][max_x];
        }
        
        return s;
    }
    void print(vector<vector<int>>& mat)
    {
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j < mat[0].size(); j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K)
    {
       vector<vector<int>> row_sum;
        for(int i = 0; i < mat.size(); i++)
        {
            int sum = 0;
            vector<int> temp = vector<int>();
            for(int j = 0; j < mat[i].size(); j++)
            {
                sum += mat[i][j];
                temp.push_back(sum);
            }
            row_sum.push_back(temp);
        }
        
        // cout<<"Mat\n";
        // print(mat);
        // cout<<"\n\n";
        // cout<<"Row_sum\n";
        // print(row_sum);
        
        vector<vector<int>> result;
        for(int i = 0;i < mat.size(); i++)
        {
            vector<int> temp = vector<int>();
            for(int j = 0; j < mat[0].size(); j++)
            {
                int s = blocksum(row_sum,i,j,K);
                temp.push_back(s);
            }
            result.push_back(temp);
        }
        return result;
    }
};
