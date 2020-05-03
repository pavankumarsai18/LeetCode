class Solution {
private:
    string toString(int s)
    {
        string result = "";
        
        while(s > 0)
        {
            string b = "0";
            
            if(s&1)
            {
                b = "1";
            }
            
            result = b + result;
            s>>=1;
            
        }
       
        return result;
    }
public:
    int minFlips(int a, int b, int c)
    {
        string A = toString(a);
        string B = toString(b);
        string C = toString(c);
        
        int numflips = 0;
        
        int sz = (A.size() > B.size())? A.size():B.size();
        sz = (sz > C.size())? sz:C.size();
        
        while(A.size() != sz){A = "0"+A;}
        while(B.size() != sz){B = "0"+B;}
        while(C.size() != sz){C = "0"+C;}
        
        for(int i = 0; i < sz; i++)
        {
            if(C[i] == '0')
            {
                if(A[i] == '1' && B[i] == '1')
                {
                    numflips += 2;
                }
                else if(A[i] == '0' && B[i] == '0'){;}
                else
                {
                    numflips += 1;
                }
            }
            else
            {
                if(A[i] == '1' || B[i] == '1')
                {;}
                else{numflips += 1;}
            }

        }
        
        return numflips;
        
    }
};
