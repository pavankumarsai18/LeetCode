class Solution {
public:
    vector<string> findRepeatedDnaSequences(string text) 
    {
        // Rabin Karp algorithm
        
        vector<string> ans;
        vector<int>    nums;
        unordered_set<string> repeatingStrings;
        unordered_set<long long> seen;
        
        unordered_map<int, int> val;
        val['A'] = 0; val['C'] = 1; val['G'] = 2; val['T'] = 3;
        
        const int patternSize = 10;
        const int textSize    = text.size();
        long long h = 0;
        
        for(int i = 0; i < textSize; i++)
        {
            nums.push_back(val[text[i]]);
        }
        
        for(int start = 0; start <  textSize - patternSize + 1; start++)
        {
            if(start != 0)
            {
                h <<= 2;
                h |= nums[start + patternSize - 1];
                h &= ~(3 << 2*patternSize);
            }
            else
            {
                for(int i = 0; i < patternSize; i++)
                {
                    h <<=2;
                    h |= nums[i];
                }
            }
            
            if(seen.find(h) != seen.end())
            {
                repeatingStrings.insert(text.substr(start,patternSize));
            }
            seen.insert(h);
            
        }
        
        for(const string & repeatingString: repeatingStrings)
            ans.push_back(repeatingString);
        return ans;
        
    }
};
