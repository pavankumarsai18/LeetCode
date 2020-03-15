class Solution {
public:
    double angleClock(int hour, int minutes) 
    {
        if(hour == 12)
            hour = 0;
        
        double angle = (30.00*hour + minutes/2.0) - (6.00*minutes);
        
        if(abs(angle) >= 180)
        {
           angle = 360 - abs(angle); 
        }
        return abs(angle);
        
    }
};
