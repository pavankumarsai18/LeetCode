class Solution {
public:
    string convertToBase7(int num) 
    {
        if(num == 0)
            return "0";
        
        
        string result = "";
        bool is_negative = (num > 0)? false: true;
        num = (num >= 0)? num: -1*num;
        
        while(num)
        {
            result += (num%7) + '0';
            num = num/7;
        }
        if(is_negative)
            result += '-';
        
        for(int i = 0; i < result.size()/2; i++)
        {
            swap(result[i], result[result.size()-1-i]);
        }
        
        return result;
        
        
    }
};
