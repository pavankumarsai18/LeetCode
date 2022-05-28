class Solution {
public:
    int minCostII(vector<vector<int>>& costs) 
    {
        const int n = costs.size();
        const int k = costs[0].size();
        
        vector<int> total_paint_cost = costs[0];
        
        for(int i=1; i < n; i++)
        {
            vector<int> new_total_cost(k,0);
            int second_min_color, min_color;
            min_color = second_min_color = -1;
            
            for(int color = 0; color < k; color++)
            {
                int cost = total_paint_cost[color];
                if(min_color == -1 || total_paint_cost[min_color] > cost)
                {
                    second_min_color = min_color;
                    min_color = color;
                }
                else if(second_min_color == -1|| total_paint_cost[second_min_color] > cost)
                {
                    second_min_color = color;
                }
            }
            
            for(int color = 0; color < k; color++)
            {
                if(color == min_color)
                    new_total_cost[color] = total_paint_cost[second_min_color] + costs[i][color];
                else
                    new_total_cost[color] = total_paint_cost[min_color] + costs[i][color];
            }
            total_paint_cost = new_total_cost;
        }
        
        int result = INT_MAX;
        for(int color=0; color < k; color++)
        {
            result = std::min(result, total_paint_cost[color]);
        }
        return result;
    }
};
