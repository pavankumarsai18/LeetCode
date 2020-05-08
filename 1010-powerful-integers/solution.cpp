class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) 
    {
        
        
        vector<int> result;
        
        if(bound == 0 || bound == 1)
            return result;
        

        int maxPow = log2(bound) + 1;
        
        unordered_set<int> numbers;
        
        int a = 1;
        for(int i = 0; i <= maxPow; i++)
        {
            int b = 1;
            for(int j = 0; j <= maxPow; j++)
            {
                if(a + b <= bound)
                {
                    numbers.insert(a+b);
                }
                
                if(b > bound)
                {
                    break;
                }
            
                b *= y;
            }
            
            if(a > bound)
                break;
            
            a *= x;
        }
        
        for(auto itr = numbers.begin(); itr != numbers.end(); itr++)
        {
            result.push_back(*itr);
        }
        return result;
        
    }
};
