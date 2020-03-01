class Solution {
private:
    void findMinDiff(int &x, int & y, const int target)
    {
        for(int i = 1; i*i <= target + 1; i++)
        {
            int diff = abs(x - y);
            int j;
            
            if(target%i == 0)
            {
                j = target/i;
                if(diff > abs(j - i))
                {
                    x = i;
                    y = j;
                }
            }
        }
    }
    
public:
    vector<int> closestDivisors(int num) 
    {
        int num1 = num + 1;
        int num2 = num + 2;
        
        
        int x = 1, y = num1;
        findMinDiff(x, y, num1);
        
        int x_ = 1, y_ = num2;
        findMinDiff(x_, y_, num2);
        
        if(abs(x - y) > abs(x_ - y_))
        {
            x = x_;
            y = y_;
        }
        
        vector<int> result = {x, y};
        return result;
        
    }
};
