class Solution {
public:
    int rob(vector<int>& nums) 
    {
     
        int sum = 0;
        for(int n: nums)
            sum += n;
        
        vector<vector<int>> M(nums.size()+1, vector<int>(sum+1, 0));
        
        for(int row = 1; row <= nums.size(); row++)
        {
            for(int col = 1; col <= sum; col++)
            {
                // cout<<"row "<<row<<" col "<<col<<" "<< M[row][col]<<endl;
                if(col < nums[row-1])
                {
                    M[row][col] = max(M[row-1][col], M[row][col-1]);
                }
                else
                {
                    if(row == 1)
                    {
                        M[row][col] = max(M[row-1][col], nums[row-1]);
                    }

                    else
                    {

                        M[row][col] = max(M[row-1][col], M[row-2][col] + nums[row-1]);

                    }
                }
            }      
        }
        
//         for(int row= 0; row< M.size(); row++)
//         {
//             if(row-1 < nums.size() && row >= 0)
//                 cout<< nums[row-1]<<" ";
            
//             for(int col = 0; col < M[0].size(); col++)
//             {
//                 cout<<M[row][col]<<" ";
//             }
//             cout<<endl;
//         }
        
        return M[M.size()-1][M[0].size() - 1];
    }
};
