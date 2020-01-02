class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> A;
        if(n == 0)
        {
            A.push_back(0);
            return A;
        }
        else
        {
            int min = -1*((n - 1)*n)/2;
            A.push_back(min);
            for(int i = 1; i < n; i++)
            {
                A.push_back(i);
            }
            return A;
        }
        
    }
};
