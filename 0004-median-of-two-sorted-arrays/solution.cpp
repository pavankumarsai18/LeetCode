class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) 
    {
        if(A.size() > B.size())
        {
            A.swap(B);
        }
        
        const int n = A.size();
        const int m = B.size();
        const int half = (n+m +1)/2;
        int lo = 0;
        int hi = n;
        
        while(lo <= hi)
        {
            int indA = lo + ((hi-lo)>>1);
            int indB = half - indA;
            // cout<<indA<<" "<<indB<<endl;
            
            int leftA = (indA - 1 >= 0) ? A[indA-1]: INT_MIN;
            int leftB = (indB - 1 >= 0) ? B[indB-1]: INT_MIN;
            
            int rightA = (indA < n)? A[indA]: INT_MAX;
            int rightB = (indB < m)? B[indB]: INT_MAX;

            // cout<<"leftA "<<leftA<<" leftB "<<leftB<<" rightA "<<rightA<<" rightB "<<rightB<<endl;
            if(leftA <= rightB && leftB <= rightA)
            {
                if((n&1) ^ (m&1))
                {
                    return max(leftA, leftB);
                }
                else
                {
                    return (max(leftA, leftB) + min(rightA, rightB))/2.0;
                }
            }
            else if(leftA > rightB)
            {
                hi = indA - 1;
            }
            else
            {
                lo = indA + 1;
                
            }
        }
        
        return -1;
        
    }
};
