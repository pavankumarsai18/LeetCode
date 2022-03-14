class Solution {
public:
    int minCost(vector<vector<int>>& costs) 
    {
        
        int curCost[] = {0,0,0};
        int prevCost[] = {0,0,0};
        
        for(int i = 0; i < costs.size(); i++)
        {
            for(int j = 0; j < 3; j++)
            {
                curCost[j] = costs[i][j]+min(prevCost[(j+1)%3],prevCost[(j+2)%3]);   
            }
            for(int j = 0; j < 3; j++)
                prevCost[j] = curCost[j];
        }
        
        return min(curCost[0], min(curCost[1], curCost[2]));
    }
};
