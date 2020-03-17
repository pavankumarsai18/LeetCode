class Solution {
private:
    bool goodNumber(int x)
    {
        if(x != 3 && x != 4 && x != 7)
        {
            int digit;
            while(x != 0)
            {
                digit = x%10;
                if(digit == 3 || digit == 4 || digit == 7)
                {
                    return false;
                }
                x /= 10;
            }
            return true;
        }
        return false;
    }
    
    int rotateNumber(int N)
    {
        if(N == 1 || N == 0|| N == 8)
            return N;
        
        int num_digits = ceil(log10(N));
        // if the number is a power of 10
        if(ceil(log10(N)) == floor(log10(N)))
            num_digits++;
        int result = 0;
        for(int i = num_digits - 1; i >= 0; i--)
        {
            int temp = N;
            temp = int(temp/pow(10, i))%10;
            switch(temp)
            {
                case 5: temp = 2;
                    break;
                case 2: temp = 5;
                    break;
                case 6: temp = 9;
                    break;
                case 9: temp = 6;
                    break;
                default: break;
            }
            
            result += temp;
            if(i != 0)
                result *= 10;
        }
        return result;
    }
public:
    int rotatedDigits(int N)
    {
        int result = 0;
        for(int i = 1; i <= N; i++)
        {
            if(goodNumber(i))
            {
                if(rotateNumber(i) != i){
                    result++;
                }
            }
        }
        
        return result;
    }
};
