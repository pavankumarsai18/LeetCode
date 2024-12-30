class Solution {
public:
    bool has_unique_digits(int number) {
        bool digit_seen[10] = {false};
        while (number) {
            int digit = number%10;
            if (digit_seen[digit] != false) {
                return false;
            }
            digit_seen[digit] = true;
            number /= 10;
        }
        return true;
    }

    int numberCount(int a, int b) {
        int count = 0;
        for (int number = a; number <= b; number++) {
            if (has_unique_digits(number)) {
                count++;
            }
        }
        return count;
    }
};
