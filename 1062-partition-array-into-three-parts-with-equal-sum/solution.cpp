class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) 
    {
        int sum = 0;
        for(int x: A)
        {
            sum += x;
        }
        if(sum%3 != 0)
            return false;
        
        int sum_1 = 0;
        int i_, j_ = 0;
        for(int i = 0; i < A.size();i++)
        {
            sum_1 += A[i];
            if(sum_1 == sum/3)
            {   
                i_ = i;
                int sum_2 = 0;
                for(int j = i+1; j < A.size();j++)
                {
                    sum_2 += A[j];
                    if(sum_2 ==  sum/3 && j < A.size() - 1)
                    {
                        j = j_;
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
