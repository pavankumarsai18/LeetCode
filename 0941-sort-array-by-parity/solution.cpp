class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        int odd_start = 0;
        int odd_end = 0;
        int even_end = 0;
        
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i]%2 == 0)
            {
                int temp;
                temp = A[0];
                A[0] = A[i];
                A[i] = temp;
                odd_start = 1;
                break;
            }
        }
        
        for(int i = 1; i < A.size(); i++)
        {
            // for(int j = 0; j < A.size(); j++)
            // {
            //     cout<<A[j]<<" ";
            // }
            //cout<<even_end<<" "<< odd_start<<" "<<odd_end<<"\n";
            
            if(i+1 < A.size() && A[i]%2 == 0 && A[i+1]%2 == 0)
            {
                even_end = i+1;
            }
            
            else if(i+1 < A.size() && A[i]%2 == 0 && A[i+1] %2 == 1)
            {
                if(odd_start == 1)
                {
                    odd_start = i+1;
                }
                else{
                    odd_end = i+1;
                }
            }
            
            else if(i+1 < A.size() && A[i]%2 == 1 && A[i+1]%2 == 1)
            {
                odd_end = i+1;
            }
            
            else if( i+1 < A.size() && A[i]%2 == 1 && A[i+1]%2 == 0)
            {
                // swap the start of odd with i+1
                int temp;
                temp = A[odd_start];
                A[odd_start] = A[i+1];
                A[i+1] = temp;
                odd_start ++;
                even_end ++;
            }
            
        }

        return A;
        
        
    }
};
