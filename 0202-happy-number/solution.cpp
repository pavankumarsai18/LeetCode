class Solution {
public:
    bool isHappy(int n) 
    {
        //a^2 + b^2
        
        int temp;
        int count = 0;
        int x = n;
        
        unordered_set<int> cycle;
        cycle.insert(n);
        do
        {
            vector<int>num;
            while(x != 0)
            {
                num.push_back(x%10);
                x/=10;
            }
            temp = 0;
            for(int i = 0; i < num.size(); i++)
            {
                temp += num[i]*num[i];
            }
            if(temp == 1)
                return true;
            count++;
            x = temp;
            auto itr = cycle.find(x);
            if(itr == cycle.end())
            {
                cycle.insert(x);
            }
            else
            {
                return false;
            }
        }
        while(temp != 1 && count != n);
        
        return false;
        
    }
};
