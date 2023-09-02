class Solution {
public:
    bool isVowel(char c) {
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') || (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string reverseVowels(string s) {
        int left, right;
        const int n = s.size();

        left = 0; right = n - 1;

        while (left < right) {
            while (left < right && !isVowel(s[left])) {
                left++;
            }

            while (right > left && !isVowel(s[right])) {
                right--;
            }
            
            if (left < right && isVowel(s[left]) && isVowel(s[right])) {
                swap(s[left], s[right]);
            } 
            left ++;
            right --;
        }

        return s;
    }
};
