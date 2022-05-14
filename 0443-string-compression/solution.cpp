class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int totalLen, rIndex, wIndex;
        totalLen = rIndex = wIndex = 0;
        
        while(rIndex < chars.size())
        {
            char curChar = chars[rIndex];
            int count = 0;
            while(rIndex < chars.size() && chars[rIndex] == curChar)
            {
                rIndex++;
                count++;
            }
            
            if(count == 1)
            {
                chars[wIndex++] = curChar;
                totalLen++;
            }
            else
            {
                chars[wIndex++] = curChar;
                totalLen++;
                
                string strNum = "";
                while(count)
                {
                    int digit = count%10;
                    
                    strNum += char(digit + '0');
                    count /= 10;
                }
                
                
                for(int i = strNum.size()-1; i >= 0; i--)
                {
                    chars[wIndex++] = strNum[i];
                    totalLen++;
                }
            }
        }
        return totalLen;
        
    }
};
