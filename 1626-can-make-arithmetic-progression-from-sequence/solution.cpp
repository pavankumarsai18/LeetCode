class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        const int n = arr.size();
        
        if(n == 2)
            return true;
        
        unordered_set<int> uniqueNums;
        int min, secondmin;
        min = -1; secondmin = -1;
        for(int i = 0; i < n; i++)
        {
            uniqueNums.insert(arr[i]);
            if(min == - 1 || arr[min] >= arr[i])
            {
                secondmin = min;
                min = i;
            }
            else if(secondmin == -1 || arr[secondmin] >= arr[i])
            {
                secondmin = i;
            }
        }
    

        const int diff = arr[secondmin] - arr[min];
        if(diff == 0)
        {
            for(int i = 1; i < n; i++)
            {
                if(arr[i] != arr[min])
                    return false;
            }
            return true;
        }
        
        int cur = arr[min];
        int numArithmeticProgression = 1;
        
        while(uniqueNums.find(cur + diff) != uniqueNums.end())
        {            
            numArithmeticProgression++;
            cur = cur + diff;
        }
        return (numArithmeticProgression == n);
    }
};
