class Solution {
private:
    struct line
    {
        int start;
        int end;
        line(int s, int e)
        {
            this->start = s;
            this->end = e;
        }

    };
    
    struct customHash
    {
        size_t operator()(const line & s) const 
        {
		    string s_ = to_string(s.start) + " " + to_string(s.end);
		    return std::hash<string>()(s_);
	    }
    };
    
    struct customCompare
    {
        size_t operator()(const line & a, const line &b) const 
        {
		    if(a.start <= b.start && a.end >= b.end)
                return true;
            else
            {
                return false;
                // if(a.end < b.start)
                //     return false;
                // else
                // {
                //     if(a.start <= b.start && a.end)
                // }
            }
	    }
    };
public:
    vector<int> partitionLabels(string S) 
    {

        // vector<int> result;
        unordered_map<char, int> char_end;
        // unordered_map<char, int> char_start;
        for(int i = 0; i < S.size(); i++)
        {
            char_end[S[i]] = i;
        }
        vector<int> ans;
        int j = 0, anchor = 0;
        for (int i = 0; i < S.length(); ++i) {
            j = max(j, char_end[S[i]]);
            if (i == j) {
                ans.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return ans;
        
    }
};
