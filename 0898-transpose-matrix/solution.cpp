class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A)
    {
        int num_rows = A.size();
        int num_cols = A[0].size();

        vector<vector<int>> result(num_cols);
        
        // cout << num_rows<<" "<< num_cols<<endl;
        // cout << result.size() << " " << result[0].size()<<endl;
        for(int row = 0; row < num_rows; row++)
        {
            //Swap the elements in the diag row to the diag col
            for(int col = 0; col < num_cols; col++)
            {
                result[col].push_back(A[row][col]);
            }
        }
        
        return result;
    }
};
