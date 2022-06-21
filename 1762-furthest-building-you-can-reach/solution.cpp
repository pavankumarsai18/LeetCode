class Solution {
public:
    bool isReachable(vector<array<int, 2>>& climbs, int& buildingIndex, int bricks, int ladders)
    {
        
        for(int i = 0; i < climbs.size(); i++)
        {
            int climbHeight = climbs[i][0];
            int index       = climbs[i][1];
            
            if(index > buildingIndex)
                continue;
            
            if(bricks >= climbHeight)
                bricks -= climbHeight;
            else if(ladders > 0)
                ladders--;
            else
                return false;
        }
        return true;
        
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        const int n = heights.size();
        vector<array<int, 2>> climbs;
        for(int i = 0; i < n-1; i++)
        {
            int buildingHeight     = heights[i];
            int nextBuildingHeight = heights[i+1];
            int climb              = nextBuildingHeight - buildingHeight;
            if(climb > 0)
            {
                climbs.push_back({climb, i+1});
            }
        }
        
        auto compare = [](array<int,2> & a, array<int,2> & b)
        {
          return a[0] < b[0];  
        };
        sort(climbs.begin(), climbs.end(), compare);
        
        
        int lo = 0;
        int hi = n-1;
        while(lo < hi)
        {
            int buildingIndex = lo + (hi - lo + 1)/2;
            if(isReachable(climbs, buildingIndex, bricks, ladders))
            {
                lo = buildingIndex;
            }
            else
            {
                hi = buildingIndex - 1;
            }
        }
        
        return lo;
        
    }
};
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
