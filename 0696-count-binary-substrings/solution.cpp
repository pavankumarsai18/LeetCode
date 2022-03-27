class Solution {
public:
    int countBinarySubstrings(string s) {
        
        
        vector<int> binaryCount;
        int result = 0;

        int count1, count2;
        count1 = count2 = -1;
        
        for(int i = 0; i < s.length();)
        {
            int curElement = s[i];
            int numCount = 0;
            while(i < s.length() and s[i] == curElement)
            {
                i++;
                numCount++;
            }
            
            if(count1 == -1)
            {
                count1 = numCount;
            }
            else if(count2 == -1)
            {
                count2 = numCount;
                result += min(count1, count2);
            }
            else
            {
                int temp = count2;
                count2 = numCount;
                count1 = temp;
                result += min(count1, count2);
            }
        
        }        
        return result;
        
        
        
    }
};
