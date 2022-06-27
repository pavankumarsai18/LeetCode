class Solution {
public:
    int minPartitions(string n) 
    {
        bool count[10] = {0,0,0,0,0,0,0,0,0,0};
        int ind;
        
        for(int i = 0; i < n.size(); i++)
        {
            ind = n[i]-'0';
            if(!count[ind])
                count[ind] = 1;
        }
        
        for(int num=9; num >= 0; num--)
        {
            if(count[num])
                return num;
        }
        return 0;
    }
};
