class Solution {
public:
    //remeber this
    vector<int>result{vector<int>(10000, -1)};
    
    bool divisorGame(int N) 
    {
        result[0] = 0;
        
        if(N == 1)
            return false;
        
        for(int i = 1;i <= N/2; i++)
        {
            if(N%i == 0)
            {
                if(result[N - i - 1] == -1)
                {
                    if(!divisorGame(N - i))
                    {
                        result[N - 1] = 1;
                        return true;
                    }
                    else
                    {
                        result[N - 1] = 0;
                        return false;
                    }
                }
                else
                {
                    if(result[N-i-1] == 0)
                    {
                        result[N -1] = 1;
                        return true;
                    }
                    else
                    {
                        result[N - 1] = 0;
                        return false;
                    }
                }
            }
        }
        
        result[N - 1] = 0;
        return false;
    }
};
