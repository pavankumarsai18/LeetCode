class Solution {
public:
    int bitwiseComplement(int N) 
    {
        if(N == 0)
            return 1;
        int temp = N;
        int counter = 0;
        int result = 0;
        
        while(temp != 0)
        {
            //cout<<temp<<endl;
            //cout<<"bit "<<(temp&1)<<endl;
            int x;
            if(temp&1)
                x = 0;
            else
                x = 1;
                
            x <<= counter;
            //cout<<"res "<<x<<endl;
            temp >>= 1;
            result += x;
            counter++;
        }
        
        return result;
        
    }
};
