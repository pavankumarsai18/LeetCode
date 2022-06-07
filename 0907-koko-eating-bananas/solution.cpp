class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        long long maximum = piles[0];
        for(auto pile: piles)
        {
            if(pile > maximum)
                maximum = pile;
        }
        
        
        long long lo = 1;
        long long  hi = maximum;
        
        long long minSpeed = hi;
        
        while(lo <= hi)
        {
            int eatingspeed = lo + (hi - lo)/2;
            if(eatingspeed == 0)
                break;
            
            long long time = 0;
            for(int i = 0;i < piles.size(); i++)
            {
                int bananas = piles[i];
                time += bananas/eatingspeed;
                if(bananas%eatingspeed)
                    time++;
            }
            if(eatingspeed > 0 && time <= h)
            {
                // cout<<"true\n";
                minSpeed = eatingspeed;
                hi = eatingspeed - 1;
            }
            else
            {
                // cout<<"false\n";
                lo = eatingspeed + 1;
            }
        }
        
        return minSpeed;
        
    }
};
