class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if (str1.size() < str2.size()) {
           str1.swap(str2);
        }

        const int n = str1.size();
        const int m = str2.size();

        if (str1.substr(0,m) != str2 || str1 + str2 != str2 + str1) {
            return "";
        }

        return str2.substr(0, __gcd(n, m));

    }
};
