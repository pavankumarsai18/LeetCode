class Solution {
public:
    bool isPalindrome(string s) {
        int left, right;
        const int n = s.size();

        left = 0; right = n - 1;

        while (left <= right) {
            char lChar = tolower(s[left]);
            char rChar = tolower(s[right]);
            if (isalnum(lChar))
            {
                if (isalnum(rChar)) {
                    if (rChar == lChar) {
                        left++; right--;
                    } else {
                        return false;
                    }
                } else {
                    right--;
                }
            } else {
                left++;
            }
        }

        return true;
    }
};
