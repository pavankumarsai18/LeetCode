class Solution {
public:
    bool isPalindrome(string s) {
        const int n = s.size();
        int left = 0, right = n - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            } 

            while (right > left && !isalnum(s[right])) {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        return true;
    }
};
