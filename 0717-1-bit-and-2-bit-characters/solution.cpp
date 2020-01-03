class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        int last_bit = 0;
        for(int i = 0; i < bits.size(); i++)
        {
            if(bits[i] == 0)
            {
                last_bit = 1;
            }
            else
            {
                last_bit = 2;
                i++;
            }
        }
        return last_bit == 1;
    }
};
