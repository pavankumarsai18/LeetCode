#include <unordered_map>
class Solution {
private:
    unordered_map<int, int> IMap;
    unordered_map<int, int> OMap;
    unordered_map<int, int> UMap;
    int countEndingA(int n)
    {
        return 1;
    }
    
    int countEndingE(int n)
    {
        return n;
    }
    
    int countEndingI(int n)
    {
        if(IMap.find(n) == IMap.end())
        {
            int result;
            if(n == 1)
            {
                result =1;
            }
            else if(n == 2)
            {
                result =  3;
            }
            else{
                result =  1 + (countEndingE(n-1)) + countEndingI(n - 1);
            }
            IMap[n] = result;
        }

        return IMap[n];
        
    }
    
    int countEndingO(int n)
    {
        if(OMap.find(n) == OMap.end())
        {
            int result;
            if(n == 1)
            {
                result =  1;
            }
            else if(n == 2)
            {
                result =  4;
            }
            else
            {
                result =  1 + (countEndingE(n-1)) + countEndingI(n-1) + countEndingO(n-1);
            }
            OMap[n] = result;
        }
        
        return OMap[n];
            
    }
    
    int countEndingU(int n)
    {
        if(UMap.find(n) == UMap.end())
        {
            int result;
            if(n == 1)
            {
                result = 1;
            }
            else if(n == 2)
            {
                result =  5;
            }
            else
            {
                result = 1 + (countEndingE(n-1)) + countEndingI(n-1) + countEndingO(n-1) + countEndingU(n-1);
            }
            
            UMap[n] = result;
        }
        return UMap[n];
    }
public:
    int countVowelStrings(int n) {
        
        // Nee to use DP
        if(n == 0){
            return 0;
        }
        else if(n == 1)
        {
            return 5;
        }
        else if(n == 2)
        {
            return 15;
        }

        return countEndingA(n) + countEndingE(n) + countEndingI(n) + countEndingO(n) + countEndingU(n);
        
    }
};
