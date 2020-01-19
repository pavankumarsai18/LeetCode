class Solution {
private:
    bool check_zero(int n)
    {
        int temp = n;
        while(temp != 0)
        {

            if(temp%10 == 0){
                return true;
        
            }
            temp /= 10;
        }
        return false;
    }
public:
    vector<int> getNoZeroIntegers(int n) 
    {
        vector<int> res;
        if(n == 0)
        {
            res.push_back(1);
            res.push_back(-1);
            return res;
        }
        else if(n == 1)
        {
            res.push_back(-1);
            res.push_back(2);
            return res;
        }
        else
        {
            int a = n - 1;
            int temp = a;
            bool has_zero = false;
            
            do
            {
                has_zero = false;

                if(check_zero(a) || check_zero(n - a))
                {
                    a -= 1;
                    has_zero = true;
                    
                }
                
            }while(has_zero);
            
            
            res.push_back(n - a);
            res.push_back(a);
            
            
            return res;
        }
        return res;
        
    }
};
