/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) 
    {
        vector<vector<int>> result;
        
        for(int x = 1; x < 1000; x++)
        {
            for(int y = 1; y < 1000; y++)
            {
                if(customfunction.f(x,y) == z)
                {
                    vector<int> temp;
                    temp.push_back(x);
                    temp.push_back(y);
                    result.push_back(temp);
                    break;
                }
                else if(customfunction.f(x,y) > z)
                    break;
            }
        }
        
        return result;
        
    }
};
