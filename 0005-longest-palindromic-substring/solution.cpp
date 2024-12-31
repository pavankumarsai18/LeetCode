class Solution {
public:
    string expand(int center1, int center2, string & s) {
        int left = center1;
        int right = center2;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, (right - left - 1));
    }
    string longestPalindrome(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
            string odd = expand(i, i, s);
            if (odd.size() > ans.size()) {
                ans = std::move(odd);
            }

            string even = expand(i, i+1, s);
            if (even.size() > ans.size()) {
                ans = std::move(even);
            }
        }
        return ans;
    }
};
