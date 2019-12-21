class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points)
    {
        //50 * 49 * 16
        
        double max_area = 0;
        
        for(int i = 0; i < points.size() - 2;  i++)
        {
            for(int j = i + 1; j < points.size() - 1; j++)
            {
                for(int k = j + 1; k < points.size(); k++)
                {
                    //calculate area
                    auto A = points[i];
                    auto B = points[j];
                    auto C = points[k];

                    double temp_area = abs(
                        (A[0]*(B[1] - C[1]) + B[0]*(C[1] - A[1]) + C[0]*(A[1] - B[1]))/(2*1.0) );
            
                    if(temp_area > max_area)
                    {
                        max_area = temp_area;
                    }

                }
            }
        }
        
        return max_area;
        
    }
};
