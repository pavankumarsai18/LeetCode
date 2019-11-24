class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        if(stones.size() < 3)
        {
            if(stones.size() == 2)
            {
                return abs(stones[0] - stones[1]);
            }
            else if(stones.size() == 1)
            {
                return stones[0];
            }
        }
        int result;
        auto temp = stones;
        std::sort(temp.begin(), temp.end());
        
        int j = temp.size()  - 1;
        
        for(int i = temp.size() - 1; i > 0; i--)
        {
            // for(int k = 0; k < temp.size(); k++)
            // {
            //     cout<<temp[k]<<" "; 
            // }
            //cout<<endl;
            
            if(temp[j] != temp[j - 1])
            {
                temp[j] = temp[j] - temp[j - 1];
                
                temp[j - 1] = 0;
                std::swap(temp[temp.size() - i - 1], temp[j - 1]);
            }
            
            else
            {
                temp[j] = 0;
                temp[j - 1] = 0;
                std::swap(temp[temp.size() - i], temp[j]);
                std::swap(temp[temp.size() - i-1], temp[j - 1]);
            }
            //cout<<"2-------\n";
            // for(int k = 0; k < temp.size(); k++)
            // {
            //     cout<<temp[k]<<" "; 
            // }
            // cout<<endl;
            // cout<<*(temp.begin() + temp.size() - i)<<endl;
            std::sort((temp.begin() + temp.size() - i), temp.end());
        }
        
        return temp[temp.size() - 1];
    }
};
