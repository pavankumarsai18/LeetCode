class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) 
    {
        //dp
        //sum = 8
        vector<int> result(A.size(), 0);
        
        int sum = 0;
        for(int& x: A)
        {
            if(x%2 == 0)
                sum += x;
        }
    
        for(int i = 0; i < queries.size(); i++)
        {
            //  if the result is even
            if((queries[i][0] + A[queries[i][1]])%2 == 0)
            {
                //if the prev value is even
                if(A[queries[i][1]] %2 == 0)
                {
                    if(i == 0)
                        result[i] = sum + queries[i][0];
                    else
                        result[i] = result[i - 1] + queries[i][0];
                }
                //if the prev value is odd
                else
                {
                    if(i == 0)
                        result[i] = sum + A[queries[i][1]] + queries[i][0];
                    else
                        result[i] = result[i - 1]  + A[queries[i][1]] + queries[i][0];
                        
                }
            }
            //if the result is odd
            else
            {
                //if the prev value is even
                if(A[queries[i][1]] %2 == 0)
                {
                    if(i == 0)
                        result[i] = sum - A[queries[i][1]];
                    else
                        result[i] = result[i - 1] - A[queries[i][1]];
                        
                }
                //if the prev value is odd
                else
                {
                    if(i == 0)
                        result[i] = sum;
                    else
                        result[i] = result[i - 1];
                        
                }
            }
            
            A[queries[i][1]] += queries[i][0]; 
        }
        
        return result;
        
    }
};
