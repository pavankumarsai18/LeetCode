class Solution {
public:
    string convert(string s, int numRows) 
    {
        vector<string> zigZag(numRows, "");
        const int n = s.size();
        int i = 0;
        while(i < n)
        {
            int numSteps = 0;
            // down
            while(i < n && numSteps < numRows)
            {
                zigZag[numSteps] += s[i];
                i++;
                numSteps++;
            }
            //up
            numSteps = numRows-2;
            while(i < n && numSteps >= 1)
            {
                zigZag[numSteps] += s[i];
                i++;
                numSteps--;
            }
        }
        
        string ans = "";
        for(int i = 0; i < numRows; i++)
        {
            ans += zigZag[i];
        }
        
        return ans;
    }
};
