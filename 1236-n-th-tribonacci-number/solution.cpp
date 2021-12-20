class Solution {
public:
    int tribonacci(int n) {

        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        else if(n == 2)
            return 1;
        else
        {
            int a, b, c;
            a = 0;
            b = c = 1;
            
            for(int i = 0; i < n-2; i++){
                int temp_a, temp_b;
                temp_a = a;
                a = b;
                temp_b = b;
                b = c;            
                c = temp_a + temp_b + c;            
            }
            
            return c;
        }
        
    }
};
