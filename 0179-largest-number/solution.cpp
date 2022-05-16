class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        
        vector<string> strNums;
        
        bool allZero = false;
        
        for(int i = 0; i < nums.size(); i++)
        {
            string number = to_string(nums[i]);
            strNums.push_back(number);
        }
        
        auto comp = [](string & a, string & b)
        {
            string comb1 = a+b;
            string comb2 = b+a;
            
            int index1, index2;
            index1 = index2 = 0;
            
            const int n = comb1.size();
            
            while(index1 < n && index2 < n)
            {
                if(comb1[index1] == comb2[index2])
                {
                    index1++;
                    index2++;
                }
                else
                {
                    return comb1[index1] < comb2[index2];
                }
            }
            
            return comb1 < comb2;
        };
        
        sort(strNums.begin(), strNums.end(), comp);
        
        string result = "";
        
        
        
        for(int i = strNums.size()-1; i >= 0; i--)
        {
            result += strNums[i];
        }
        
        if(result[0] == '0')
        {
            return "0";
        }
        
        return result;
        
    }
};
