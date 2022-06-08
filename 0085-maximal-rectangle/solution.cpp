class Solution {
public:
    int maxRectangeHistogram(vector<int> histogram)
    {
        cin.tie(nullptr)->sync_with_stdio(false);

        const int length = histogram.size();
        int maxArea = 0;
        stack<pair<int,int>> rectangles;
        
        for(int i = 0; i < histogram.size(); i++)
        {
            int start = i;
            
            while(rectangles.size() && rectangles.top().second > histogram[i])
            {
                int index  = rectangles.top().first;
                int height = rectangles.top().second;
                
                rectangles.pop();
                
                maxArea    = max(maxArea, height*(i - index));
                start      = index;
                
            }
            rectangles.push({start, histogram[i]});
        }
        
        while(rectangles.size())
        {
            int index  = rectangles.top().first;
            int height = rectangles.top().second;

            maxArea = max(maxArea, height*(length - index));
            rectangles.pop();
        }
        
        return maxArea;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        const int num_rows = matrix.size();
        const int num_cols = matrix[0].size();
        
        vector<int> histogram_heights(num_cols, 0);
        int maxArea = 0;
        
        for(int r = 0; r < num_rows; r++)
        {
            for(int c = 0; c < num_cols; c++)
            {
                if(matrix[r][c] == '1')
                {
                    histogram_heights[c]++;
                }
                else
                {
                    histogram_heights[c] = 0;
                }
            }
            
            int area = maxRectangeHistogram(histogram_heights);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};
