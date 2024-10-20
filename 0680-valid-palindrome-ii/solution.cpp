class Solution {
public:
    bool isPalindrome(string & s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }


    bool validPalindrome(string s) {
        int left = 0, right = s.size()  - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                string skipL = s.substr(left + 1, (right - left));
                string skipR = s.substr(left, (right - left));
                return (isPalindrome(skipL) || isPalindrome(skipR));
            }

            left++;
            right--;
        }

        return true;
    }
};
