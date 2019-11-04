class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> output;
        for(int i = 1; i <= n; i++)
        {
            string result = "";
            if(i%3 == 0)
            {
                 result += "Fizz";
            }
            if(i%5 == 0)
            {
                result += "Buzz";
            }
            else if( i%3 != 0 && i%5 != 0)
            {
                int temp = i;
                while(temp != 0)
                {
                    int digit = temp%10;
                    //cout<<digit<<endl;
                    result += static_cast<char>(digit + 48);
                    //cout<<result<<endl;
                    temp/=10;
                }
                //reverse it
                for(int i = 0; i < result.size()/2 ;i++)
                {
                    char temp = result[i];
                    result[i] = result[result.size() - 1 - i];
                    result[result.size() - 1 - i] = temp;
                }
            }
            //cout<<i<<" "<<result<<endl;
            output.push_back(result);

        }
        return output;   
    }
};
