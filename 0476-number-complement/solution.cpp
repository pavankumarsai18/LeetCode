class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int temp = num;
        while(temp != 0)
        {
            // cout<<num<<endl;
            result <<= 1;
            result |= 1;
            temp >>= 1;
            
        }
        // cout<<result;
        return (result^num);
        
    }
};
