class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        
        
        int lo = 0;
        int hi = height.size() - 1;
        
        int maxarea = 0;
        while(lo < hi)
        {
            int area = (hi - lo)*(min(height[lo], height[hi]));
            maxarea = max(area, maxarea);
            
            if(height[lo] == min(height[lo], height[hi]))
                lo++;
            else
                hi--;
        }
        
        return maxarea;
    }
};
