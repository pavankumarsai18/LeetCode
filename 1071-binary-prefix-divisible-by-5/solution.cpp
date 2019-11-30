class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) 
    {
        vector<bool> result;
        vector<int> number;
        
        for(int i = 0; i < A.size(); i++)
        {
            if(i == 0)
            {
                int x = A[0];
                number.push_back(x);
                if(x%5 == 0)
                    result.push_back(true);
                else
                    result.push_back(false);
            }
            else
            {
                int x = number[i - 1];
                x *= 2;
                //x %= 5;
                x += A[i];
                x%=5;
                number.push_back(x);
                if(x == 0)
                    result.push_back(true);
                else
                    result.push_back(false);
            }
        }
        
        return result;
        
    }
};
