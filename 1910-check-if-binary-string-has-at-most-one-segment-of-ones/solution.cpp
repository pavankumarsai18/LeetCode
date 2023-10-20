class Solution {
public:
    bool checkOnesSegment(string s) {
        const int n = s.size();
        int start = 0;
        bool foundSegment = false;
        int i = 0;
        while(i < n){
            if (s[i] == '1') {
                if (foundSegment) return false;
                while (i < n && s[i] == '1') {
                    foundSegment = true;
                    ++i;
                }
            } else {
                ++i;
            }
        }

        return true;
    }
};
