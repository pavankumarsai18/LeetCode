class Solution {
private:
    void shift(string & A)
    {
        string temp = A;
        
        for(int i = 1; i < A.size(); i++)
        {
            A[i] = temp[i - 1];
        }
        A[0] = temp[temp.size() - 1];
    }
public:
    bool rotateString(string A, string B) 
    {
        // shift the string one by one till the string size
        // and compare the two strings
        // if it is equal then return true
        if(A.size() != B.size())
            return false;
        if(A == B)
            return true;
        int s = 0;
        
        while(s < A.size())
        {
            if(A == B)
                return true;
            else
            {
                shift(A);
            }
            s++;
        }
        return false;
    }
};
