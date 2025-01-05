class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> numShifts(s.size() + 1, 0);
        for (auto & shift: shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 1) {
                numShifts[start]++;
                numShifts[end + 1]--;
            } else {
                numShifts[start]--;
                numShifts[end + 1]++;
            }
        }
        
        int rollingShifts = 0;
        
        for (int idx = 0; idx < s.size(); idx++) {
            rollingShifts += numShifts[idx];
            rollingShifts %= 26;
            s[idx] = (s[idx] - 'a' + rollingShifts + 26) % 26 + 'a';
        }

        return s;
    }
};
