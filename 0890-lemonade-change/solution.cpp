class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        if(bills.size() == 0)
            return false;
        
        int profit = 5;
        int arr[] = {1,0,0};
        
        if(bills[0] != 5)
            return false;
        
        for(int i = 1; i < bills.size(); i++)
        {

            if(bills[i] == 5)
            {
                profit += 5;
                arr[0] ++;
            }
            else if(bills[i] == 10)
            {
                if(profit >= 5 && arr[0] > 0)
                {
                    profit -= 5;
                    arr[0] -= 1;
                }
                else
                {
                    return false;
                }
                profit += 10;
                arr[1] ++;
            }
            else if(bills[i] == 20)
            {
                if(profit >= 15 && arr[0] > 0)
                {
                    
                    profit -= 15;
                    
                    arr[0]--;
                    if(arr[1] == 0 && arr[0] >= 2)
                    {
                        arr[0] -= 2;
                    }
                    else if(arr[1] > 0)
                    {
                       arr[1]--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
                profit += 20;
                arr[2]++;
            }

        }
        return true;
        
    }
};
