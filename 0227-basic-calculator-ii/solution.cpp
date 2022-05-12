class Solution {
public:
    int calculate(string s) 
    {
        const int length = s.size();
        
        int curNumber, lastNumber, result;
        curNumber = lastNumber = result = 0;
        
        char sign = '+';
        
        for(int i = 0; i < length; i++)
        {
            char curChar = s[i];
            if(isdigit(curChar))
            {
                curNumber = curNumber*10 + (curChar - '0');
            }
            if(!isdigit(curChar) && curChar != ' ' || i == length - 1)
            {
                if(sign == '+' || sign == '-')
                {
                    result += lastNumber;
                    lastNumber = curNumber;
                    
                    if(sign == '-')
                        lastNumber*=-1;

                }
                else if(sign == '*')
                {
                    lastNumber = lastNumber*curNumber;
                }
                else if(sign == '/')
                {
                    lastNumber = lastNumber/curNumber;
                }
                
                sign = curChar;
                curNumber = 0;
            }
        }
        
        return result + lastNumber;

    }
};
