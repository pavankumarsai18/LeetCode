class Solution {
public:
    string addStrings(string num1, string num2)
    {

        string result = "";
        
        int max = num2.size();
        int min = num1.size();
        if(max < num1.size())
        {
            max = num1.size();
            min = num2.size();
        }
        int carry = 0;
        
        for(int i = 0; i < num1.size()/2; i++)
        {
            std::swap(num1[i], num1[num1.size() - i - 1]);
        }
        
        for(int i = 0; i < num2.size()/2; i++)
        {
            std::swap(num2[i], num2[num2.size() - i - 1]);
        }
        
        for(int i = 0; i < max; i++)
        {
            if(i < min)
            {
                int temp = (static_cast<int>(num1[i]) - 48) + (static_cast<int>(num2[i]) - 48) + carry;
                if(temp >= 10)
                {
                    temp -= 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
                result += static_cast<char>(temp + 48);
            }
            else
            {
                if(num2.size() < num1.size())
                {  
                    for(int j = min; j < num1.size(); j++)
                    {
                        int temp = (static_cast<int>(num1[j]) - 48) + carry;

                        if(temp >= 10)
                        {
                            temp -= 10;
                            carry = 1;
                        }
                        else
                        {
                            carry = 0;
                        }
                        result += static_cast<char>(temp + 48) ;
                    }
                    i = num1.size();
                    
                }
                else
                {
                    for(int j = min; j < num2.size(); j++)
                    {
                        int temp = (static_cast<int>(num2[j]) - 48) + carry;

                        if(temp >= 10)
                        {
                            temp -= 10;
                            carry = 1;
                        }
                        else
                        {
                            carry = 0;
                        }
                        result += static_cast<char>(temp+48);
                    }
                    i = num2.size();
                }
            }
        }
        
        if(carry == 1)
            result += "1";
        
        for(int i = 0; i < result.size()/2; i++)
        {
            std::swap(result[i], result[result.size() - i - 1]);
        }
        
        return result;
    }
};
