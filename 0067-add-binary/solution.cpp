class Solution {
public:
    string addBinary(string a, string b)
    {
        string result = "";
        string carry = "0";
        
        if(a.size() > b.size())
        {
            while(a.size() != b.size())
            {
                b = "0" + b;
            }
        }
        else if(a.size() < b.size())
        {
            while(a.size() != b.size()){
                a = "0" + a;
            }
        }
        //cout<<"a = "<<a<<endl;
        //cout<<"b = "<<b<<endl;
        
        // for(int i = 0; i < a.size()/2; i++)
        //     a[i]  = a[a.size() - i - 1];
        // for(int i = 0; i < b.size()/2; i++)
        //     b[i]  = b[b.size() - i - 1];
        
        for(int i = a.size() - 1; i >= 0; i--)
        {
            //cout<<"result = "<< result<<endl;
            //cout<<"a[i] "<<a[i] << " "<< "b[i] "<< b[i]<<"carry "<<carry<<endl;
            if      (a[i] == '0' && b[i] == '0' && carry == "0")
            {
                result = "0" + result;
            }
            else if (a[i] == '0' && b[i] == '0' && carry == "1")
            {
                result = "1" + result;
                carry = "0";
            }
            else if (a[i] == '0' && b[i] == '1' && carry == "0")
            {
                result = "1" + result;
            }
            else if (a[i] == '0' && b[i] == '1' && carry == "1")
            {
                result = "0" + result;
                carry = "1";
            }
            else if (a[i] == '1' && b[i] == '0' && carry == "0")
            {
                result = "1" + result;
            }
            else if (a[i] == '1' && b[i] == '0' && carry == "1")
            {
                result = "0" + result;
                carry = "1";
            }
            else if (a[i] == '1' && b[i] == '1' && carry == "0")
            {
                result = "0" + result;
                carry = "1";
            }
            else if (a[i] == '1' && b[i] == '1' && carry == "1")
            {
                result = "1" + result;
                carry = "1";
            }
            
            //cout<<"result 2 = "<< result<<endl;
        }
        if(carry == "1")
            result = "1" + result;
        return result;
        
    }
};
