class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        const int n = chars.size();
        int prev = 0;
        for (int cur = 0; cur < n; ++cur, ++prev) {
            int numOccurances = 1;
            char curChar = chars[cur];
            while (cur + 1 < n && curChar == chars[cur+1]) {
                ++cur;
                ++numOccurances;
            }
            
            ++ans;
            

            if (prev != cur) {
                chars[prev] = curChar;
            }
            if(numOccurances > 1) {
                string numStr = to_string(numOccurances);
                ans += numStr.size();
                for (auto & c : numStr) {
                    chars[++prev] = c;
                }

                // chars[++prev] = curChar;


            }

        }

        return ans;
    }
};
