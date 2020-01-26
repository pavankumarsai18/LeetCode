class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int p = log2(N);
        p *= 2;
        while(p >= 0)
        {
            unordered_map<int, int> num_digits;
            unordered_map<int,int> num_two;
            
            int temp = N;
            while(temp > 0)
            {
                if(num_digits.find(temp%10) == num_digits.end())
                {
                    num_digits[temp%10] = 1;
                }
                else
                {
                    num_digits[temp%10] += 1;
                }
                temp /= 10;
            }
            
            temp = pow(2,p);
            while(temp > 0)
            {
                if(num_two.find(temp%10) == num_two.end())
                {
                    num_two[temp%10] = 1;
                }
                else
                {
                    num_two[temp%10] += 1;
                }
                temp /= 10;
            }
            
            bool does_contain = true;
            if(num_two.size() != num_digits.size())
            {
                p --;
                continue;
            }
           for(auto itr = num_two.begin(); itr != num_two.end(); itr++)
            {

               if(num_two.find(itr->first) != num_two.end())
               {
                    if( num_digits[itr->first] != num_two[itr->first])
                    {
                        does_contain = false;
                        break;
                    }
               }  
            }
            if(does_contain)
            {
                // cout<<p<<endl;
                return true;
            }

            
            p--;
        }
        
        return false;
    }
};
