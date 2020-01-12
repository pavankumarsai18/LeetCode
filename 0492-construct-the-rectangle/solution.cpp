class Solution {
public:
    vector<int> constructRectangle(int area) 
    {
        
        if(area <= 0)
        {
            vector<int> result;
            return result;
        }
        
        int L = sqrt(area);
        int W = area/L;
        
        if(L * W == area)
        {
            vector<int> result;
            if(L < W)
            {
                result.push_back(W);
                result.push_back(L);
                return result;
            }
            else
            {
                result.push_back(L);
                result.push_back(W);
                return result;
            }
        }
        else
        {
            while( W*L != area)
            {
                // cout<<W<<" "<<L<<endl;
                if(W > 1)
                    W -= 1;
                else
                    break;
                
                L = area/W;
                if(L * W == area)
                {
                    vector<int> result;
                    result.push_back(L);
                    result.push_back(W);
                    return result;
                }
            }
            vector<int> result;
            result.push_back(area);
            result.push_back(1);
            
            return result;
        }
        
    }
};
