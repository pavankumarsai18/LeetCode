class Solution {
public:
    double slope(vector<int> &A, vector<int> & B)
    {
        if(A[0] == B[0])
            return 2147483648;
        return (A[1] - B[1])/(A[0] - B[0]);
    }
    double intercept(vector<int> &A, double slope)
    {
        return A[1] - (slope*A[0]);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        int m = slope(coordinates[0], coordinates[1]);
        int b = intercept(coordinates[0], m);
        
        for(int i = 0; i < coordinates.size() - 1; i++)
        {
            if( m != slope(coordinates[i], coordinates[i+1]))
                return false;
            if( b != intercept(coordinates[i], m))
                return false;
        }
        return true;
        
    }
};
