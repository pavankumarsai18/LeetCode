class Solution {
public:
    int getMaximumGenerated(int n) 
    {
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        
        vector<int> array;
        
        array.push_back(0);
        array.push_back(1);
        
        int result = 0;
        
        for(int i = 2; i <= n; i++)
        {
            if(i%2 == 0)
            {
                array.push_back(array[i/2]);
                
            }
            else
            {
                array.push_back(array[i/2] + array[(i/2) + 1]);
            }
            
            if(result < array[array.size() - 1])
            {
                result = array[array.size() - 1];
            }
        }
        
        return result;
        
        
    }
};
