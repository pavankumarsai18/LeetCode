class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        vector<vector<int>> Table;
        
        for(int i = 0;i < text2.size() + 1; i++)
        {
            Table.push_back(vector<int>(text1.size()+1,0));
        }
        
        
        for(int row = 1; row < text2.size() + 1; row++)
        {
            for(int col = 1; col < text1.size() + 1; col++)
            {
                if(text1[col-1] == text2[row-1])
                {
                    Table[row][col] = Table[row-1][col-1] + 1;
                }
                else
                {
                    Table[row][col] = max(Table[row-1][col], Table[row][col-1]);
                }
            }
        }
        
        return Table[Table.size() - 1][Table[0].size() - 1];
    }
};
