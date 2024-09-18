class Solution {
public:
    string removeLeadingZeros(string & number) {
        if (number.size() == 1) return number;

        int lastleadingZeroIdx = -1;
        int curIdx = 0;
        while (curIdx < number.size() && number[curIdx] == '0') {
            lastleadingZeroIdx = curIdx;
            curIdx++;
        }

        if (lastleadingZeroIdx != -1) return number.substr(lastleadingZeroIdx);
        return number;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [] (int & num1, int & num2) {
            string num1_str = std::to_string(num1);
            string num2_str = std::to_string(num2);

            return num1_str + num2_str > num2_str + num1_str;
        });

        string largestNumberPossible = "";
        for (int i = 0; i < nums.size(); ++i) {
            largestNumberPossible += std::to_string(nums[i]);
        }

        return removeLeadingZeros(largestNumberPossible);
    }
};
