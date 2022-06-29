class Solution {
public:
    string intToRoman(int num) 
    {
        string ans = "";
        
        while(num)
        {
            if(num >= 1000)
            {
                ans += "M";
                num -= 1000;
            }
            else if(num >= 900)
            {
                ans += "CM";
                num -= 900;
            }
            else if(num >= 500)
            {
                ans += "D";
                num -= 500;
            }
            else if(num >= 400)
            {
                ans +=  "CD";
                num -= 400;
            }
            else if(num >= 100)
            {
                ans += "C";
                num-= 100;
            }
            else if(num >= 90)
            {
                ans += "XC";
                num -= 90;
            }
            else if(num >= 50)
            {
                ans += "L";
                num -= 50;
            }
            else if(num >= 40)
            {
                ans += "XL";
                num-= 40;
            }
            else if(num >= 10)
            {
                ans += "X";
                num -= 10;
            }

            switch(num)
            {
                case 1: 
                    ans += "I";  num = 0; break;
                case 2:
                    ans += "II"; num = 0; break;
                case 3:
                    ans +=  "III"; num = 0; break;
                case 4:
                    ans +=  "IV"; num = 0; break;
                case 5:
                    ans +=  "V"; num = 0; break;
                case 6:
                    ans +=  "VI"; num = 0; break;
                case 7:
                    ans +=  "VII"; num = 0; break;
                case 8:
                    ans +=  "VIII"; num = 0; break;
                case 9:
                    ans +=  "IX"; num = 0; break;
            }

        }
        return ans;
    }
};
