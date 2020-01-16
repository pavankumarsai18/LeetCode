class Solution {
private: 
    vector<int> pay;
    
    int mincost(vector<int>& cost, int index, vector<int>&pay)
    {
        // cout<<"index "<<index<<"\n";
        if(index >= cost.size())
            return -1;
        
        if(pay[index] != -1)
            return pay[index];
        
        int c = 0;
        c += cost[index];
        
        int x = mincost(cost, index+1, pay);
        int y = mincost(cost, index+2, pay);
        
        // cout<<"x "<<x<<" y "<<y<<endl;
        if(x > 0 || y > 0)
        {
            if(x >= y && y > 0)
                c += y;
            else if(x > 0 && y >= x)
                c += x;
        }
        // cout<<c<<endl;
        pay[index] = c;
        return c;
        
    
    }
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        for(int i = 0; i < cost.size(); i++)
            this->pay.push_back(-1);
        
        int c = mincost(cost, 0, pay);
        int C = mincost(cost, 1, pay);
        
        if(c < C)
            return c;
        return C;
    }
};
