class Solution {
private:
    string decimalLeftShift(const string& num, const int & numTimes)
    {
        // cout<<"decimalLeftShift "<<num<<" "<<numTimes<<endl;
        string result = num;
        for(int i = 0; i < numTimes; i++)
        {
            result += "0";
        }
        // cout<<"left shift "<<result<<endl;
        return result;
    }
    
    string addTwoStrings(const string &s1, const string& s2)
    {
        // cout<<"add two strings "<<s1<<" "<<s2<<endl;
        int carry = 0;
        string A = (s1.size() > s2.size())? s1: s2;
        string B = (s1.size() <= s2.size())?s1: s2;
        
        string result = "";
        int j = A.size() - 1;
        
        for(int i = B.size() - 1; i >= 0; i--, j--)
        {
            int add = int(A[j] -'0') + int(B[i] - '0') + carry;
            carry = (add - add%10)/10;
            add = add%10;
            result += (char(add + '0'));
        }
        
        for(; j >=0; j--)
        {
            int add = int(A[j] -'0') + carry;
            carry = (add)/10;
            add = add%10;
            result += (char(add + '0'));
        }
        if(carry)
        {
            result += (char(carry + '0'));
        }
        
        for(int i = 0; i < result.size()/2; i++)
        {
            std::swap(result[i], result[result.size() - 1 - i]);
        }
        

        // cout<<"result "<<result<<endl;
        return result;
    }
    string singleDigitMultiply(const string& num, const char & digit)
    {
        // cout<<"Single Mulitply "<<num<<" "<<digit<<endl;
        int d = digit - (int)'0';
        
        int carry = 0;
        string result = "";
        
        for(int i = num.size() - 1; i >=0; i--)
        {
            int mult = int(num[i] - '0') * d + carry;
            carry = (mult)/10;
            mult %= 10;
            
            result += (char(mult + '0'));
        }
        
        if(carry)
            result += (char(carry + '0'));
        
        for(int i = 0; i < result.size()/2; i++)
        {
            std::swap(result[i], result[result.size() - 1- i]);
        }
        // cout<<"result mult "<<result<<endl;
        return result;
    }
    
    string zeros(const int & num)
    {
        string result = "";
        for(int i = 0 ;i < num; i++)
        {
            result += "0";
        }
        return result;
    }
    
    bool isZero(const string & s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '0')
                return false;
        }
        return true;
    }
public:
    string multiply(string num1, string num2) 
    {
        
        string A = (num1.size() > num2.size())?num1 :num2;
        string B = (num1.size() <= num2.size())?num1 : num2;
        
        if(isZero(A) || isZero(B))
            return "0";
        
        // cout<<"A "<<A<<endl;
        // cout<<"B "<<B<<endl;
        string result = zeros(A.size());

        for(int i = B.size() - 1; i >= 0; i--)
        {
            
            result = addTwoStrings(result, decimalLeftShift(singleDigitMultiply(A, B[i]), B.size() - 1 - i));
            
            // cout<<"result "<<result<<endl;
        }
        
        
        
        return result;
        
    }
};
