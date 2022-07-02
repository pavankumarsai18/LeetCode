class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
    {
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        const int n = horizontalCuts.size();
        const int m = verticalCuts.size();  
        
        int maxHeight = max(horizontalCuts[0],h-horizontalCuts[n-1]);
        int maxWidth  = max(verticalCuts[0], w-verticalCuts[m-1]);

        for(int i = 1; i < n; i++)
        {
            maxHeight = max(maxHeight, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
        for(int i = 1; i < m; i++)
        {
            maxWidth = max(maxWidth, verticalCuts[i] - verticalCuts[i-1]);  
        }
        
        long long area = 1LL*maxWidth*maxHeight;
        area %= 1000000007;
        return static_cast<int>(area);
    
    }
};
