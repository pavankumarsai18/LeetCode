class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        const int n = heights.size();
        int maxArea = 0;
        stack<pair<int,int>> S;
        
        for(int i = 0; i < heights.size(); i++)
        {
            int start = i;
            
            while(S.size() && S.top().second > heights[i])
            {
                int index = S.top().first;
                int h     = S.top().second;
                
                S.pop();
                
                maxArea = max(maxArea, h*(i - index));
                start = index;
            }
            S.push({start, heights[i]});
        }
        
        while(S.size())
        {
            int index = S.top().first;
            int h     = S.top().second;

            S.pop();
            
            maxArea = max(maxArea, h*(n - index));

        }
        return maxArea;
        
    }
};
