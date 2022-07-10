class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        const int n = cost.size();
        int cost_second = cost[n-2];
        int cost_first  = cost[n-1];
        int temp;
        
        for(int stair = n - 3; stair >= 0; stair--)
        {
            temp = min(cost_first, cost_second) + cost[stair];
            cost_first = cost_second;
            cost_second = temp;

        }
        
        return min(cost_second, cost_first);
        
    }
};
