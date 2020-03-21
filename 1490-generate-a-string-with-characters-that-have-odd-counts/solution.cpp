class Solution {
public:
    string generateTheString(int n)
    {
        // how to split a number into its odd numbers
        string result = "";
        
        if(n%2 == 0)
        {
            int a = n - 1;
            result = "";
            char c = 'a';
            for(int i = 0; i < a; i++)
            {
                result += c;
            }
            result += 'b';
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                result += 'a';
            }
            return result;
        }
        return result;
    }
};
