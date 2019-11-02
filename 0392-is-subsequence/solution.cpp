class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        size_t j = 0;
        int match_count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            while(j < t.size())
            {
                if(t[j] == s[i])
                {
                    //cout<<"j: "<<j<<" "<<"i: "<<i << endl; 
                    match_count++;
                    j++;
                    break;
                }
                j++;
            }
            if(match_count == s.size())
                return true;
            
            if(j >= t.size())
                return false;
        }
        if(match_count == s.size())
            return true;
        return false;
    }
};
