class Solution {
public:
    string complexNumberMultiply(string a, string b) 
    {
        string a1,a2;
        string b1, b2;
        a1 = a2 = b1 = b2 = "";
        int i = 0;
        for(i; i < a.size(); i++)
        {
            while(a[i] != '+')
            {
                a1 += a[i];
                i++;
            }
            if(a[i] == '+')
                break;
        }
        i++;
        for(i; i < a.size(); i++)
        {
            while(a[i] != 'i')
            {
                b1 += a[i];
                i++;
            }
            if(a[i] == 'i')
                break;
        }
        i = 0;
        for(i; i < b.size(); i++)
        {
            while(b[i] != '+')
            {
                a2 += b[i];
                i++;
            }
            if(b[i] == '+')
                break;
        }
        i++;
        for(i; i < b.size(); i++)
        {
            while(b[i] != 'i')
            {
                b2 += b[i];
                i++;
            }
            if(b[i] == 'i')
                break;
        }
        
        // cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<endl;
        
        
        int A1 = stoi(a1);
        int B1 = stoi(b1);
        int A2 = stoi(a2);
        int B2 = stoi(b2);
        
        
        int A = A1*A2 - B1*B2;
        int B = A1*B2 + A2*B1;
        string result = "";
        
        result += to_string(A);
        result += "+";
        result += to_string(B);
        result += "i";
        return result;
        
    }
};
