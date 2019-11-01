class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum_a = 0;
        int sum_b = 0;
        for(int i = 0; i < s.size(); i++)
            sum_a += static_cast<char>(s[i]);
        for(int i = 0; i < t.size(); i++)
            sum_b += static_cast<char>(t[i]);
        
        //cout<<sum_b - sum_a;
        
        return static_cast<char>(sum_b - sum_a);
        
    }
};
