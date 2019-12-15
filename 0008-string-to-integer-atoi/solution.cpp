class Solution {
public:
    bool check_overflow(int x, bool prod, int sum)
    {
        long double temp = x;
        if(prod)
            temp*= 10;
        else
            temp += sum;
        
        if(temp > pow(2, 31) - 1 || temp < -1*pow(2, 31))
            return true;
        return false;
    }
    int myAtoi(string str)
    {
        const int min = -1*pow(2, 31);
        const int max = pow(2, 31) - 1;
        
        int result = 0;
        int index = 0;
        bool is_neg = false;
        
        while(str[index] == ' ')
            index++;
        if(str[index] == '-')
        {
            index += 1;
            is_neg = true;
        }
        else if(str[index] == '+')
        {
            index +=1;
        }
        while(index < str.size())
        {
            if( !isdigit(str[index]))
                break;
            else
            {
                int temp = static_cast<int>(str[index]) - 48;
                if(!check_overflow(result, false, temp))
                    result += temp;
                else
                {
                    if(is_neg)
                        return min;
                    else
                        return max;
                }
                if(index != str.size() - 1 &&  !is_neg && isdigit(str[index + 1]))
                {
                    if(!check_overflow(result, true, 0))
                        result *= 10;
                    else
                    {
                        if(is_neg)
                            return min;
                        else
                            return max;
                    }   
                }
                else if(index != str.size() - 1 && is_neg &&  isdigit(str[index + 1]))
                {
                    if(!check_overflow(result, true, 0))
                        result *= 10;
                    else
                    {
                        if(is_neg)
                            return min;
                        else
                            return max;
                    }   
                    
                }
            }
            index++;
        }
        if(is_neg)
            result *= -1;
        return result;
    }
};
