class Solution {
public:
    bool isMonotonic(vector<int>& A) 
    {
        bool increase = false;
        bool decrease = false;
        for(int i = 1; i < A.size(); i++)
        {
            if(A[i - 1] == A[i])
                ;
            else if(A[i - 1] < A[i] &&  decrease == false )
            {
                //decrease = true;
                increase = true;
            }
            else if(A[i - 1] > A[i] && increase == false)
            {
                //increase = false;
                decrease = true;
            }
            else
            {
                return false;
            }
        }
        
        return true;
        
    }
};
