class Solution {
public:
    int minPartitions(string n) {
        int result = 0;
        
        for(char & c: n)
        {
            if(result < c - '0')
                result = c - '0';
        }
        
        return result;
    }
};
