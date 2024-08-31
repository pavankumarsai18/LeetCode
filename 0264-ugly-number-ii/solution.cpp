class Solution {
public:
    int nthUglyNumber(int n) {

        set<long> ugly = {1};
        long currentUgly = 1;

        for (int i = 0; i < n; ++i) {
            currentUgly = *ugly.begin();
            ugly.erase(ugly.begin());

            ugly.insert(currentUgly << 1);
            ugly.insert(currentUgly * 3);
            ugly.insert(currentUgly * 5);

        }

        return static_cast<int> (currentUgly);

    }
};
