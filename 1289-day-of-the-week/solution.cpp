class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) 
    {
//         int result = 0;
        
//         result += (year/10)%10;
//         result *= 10;
//         result += year%10;
        

//         result = result + (result/4);
//         //20
//         result %= 7;
//         //6
//         int temp = year/100;
//         cout<<temp<<endl;
        
//         switch(temp)
//         {
//             case 17: result += 4; break;
//             case 18: result += 2; break; 
//             case 19: result += 0; break;
//             case 20: result += 6; break;
//             case 21: result += 4; break;
//             case 22: result += 2; break;
//             case 23: result += 0; break;
//         }
//         //12
        
        
//         int month_[] = {0,3,3,6,1,4,6,2,5,0,3,5};
//         // 31 28 31 30 31 30 31 31 30 31 30 31
//         // 3 0 3   2  3  2  3  3   2  3  2  3
//         // 0 3,3,6,8,11,13,16,19,21,24,26,29
        
//         if( (year%100 == 0 && year%400 == 0) || (year%100!= 0 && year%4 == 0) )
//         {
//             result += 1;
//         }
//         //13
        
//         result += month_[month - 1];
//         //16
        
//         result += day;
//         //45
        
//         result %= 7;
        
//         //3
        
        

        static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        year -= month < 3;
        int result = (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
        string result_;
        switch(result)
        {
            case 0: result_ = "Sunday";
                break;
            case 1: result_ = "Monday";
                break;
            case 2: result_ = "Tuesday";
                break;
            case 3: result_ = "Wednesday";
                break;
            case 4: result_ = "Thursday";
                break;
            case 5: result_ = "Friday";
                break;
            default: result_ = "Saturday";
                break;  
        }
         
        return result_;
        
    }
};
