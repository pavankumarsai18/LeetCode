class Solution {
public:
    string convertDigitToWord(int num)
    {
        switch(num)
        {
            case 1: return "One"; 
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
        }
        return "";
    }
    
    string convertTwoDigitToWord(int num)
    {
        switch(num)
        {
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
            case 20: return "Twenty";
            case 30: return "Thirty";
            case 40: return "Forty";
            case 50: return "Fifty";
            case 60: return "Sixty";
            case 70: return "Seventy";
            case 80: return "Eighty";
            case 90: return "Ninety";
        }
        if(num < 10) return "";
        return convertTwoDigitToWord(num - num%10) + " " + convertDigitToWord(num%10);
    }
    
    string convertToWord(int num)
    {
        int hundreds = num/100; num -= (num/100)*100;
        int tens     = num/10; num  -= (num/10)*10;
        int ones     = num;
        string ans = "";
        if(hundreds > 0)
        {
            ans += convertDigitToWord(hundreds) + " Hundred";
        }
        if(tens > 0)
        {
            if(hundreds > 0) ans += " ";
            ans += convertTwoDigitToWord(tens*10 + ones);
        }
        else
        {
            if(hundreds > 0 && ones > 0) ans += " ";
            ans += convertDigitToWord(ones);
        }

        return ans;   
    }
    
    string numberToWords(int num) 
    {
        if(num == 0) return "Zero";
        string ans = "";
        
        int value;
        for(const int & place: {9, 6, 3, 0})
        {
            value = num/pow(10, place);
            num -= value*pow(10, place);
            
            if(value > 0)
            {
                ans += convertToWord(value);
                switch(place)
                {
                    case 9: ans += " Billion"; break;
                    case 6: ans += " Million"; break;
                    case 3: ans += " Thousand"; break;
                }
                if(num > 0) ans += " ";
            }
            
           
        }
        
        return ans;
        
    }
};
