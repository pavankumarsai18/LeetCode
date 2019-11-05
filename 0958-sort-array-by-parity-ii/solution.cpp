class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) 
    {
        vector<int>result;
        stack<int> even;
        stack<int>odd;
        for(int i = 0; i < A.size(); i++)
        {
            //odd
            if(A[i]%2)
                odd.push(A[i]);
            else
                even.push(A[i]);
        }   
        
        for(int i = 0; i < A.size(); i++)
        {
            //even
            if(i%2 == 0)
            {
                result.push_back(even.top());
                even.pop();
            }
            //odd
            else
            {
                result.push_back(odd.top());
                odd.pop();
            }
        }
        return result;
        
    }
};
