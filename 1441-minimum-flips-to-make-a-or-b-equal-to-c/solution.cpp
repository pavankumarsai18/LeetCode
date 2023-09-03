class Solution {
public:
    int minFlips(int a, int b, int c) {
        int numFlips = 0;

        while (c | a | b) {
            bool cBit = (c & 1);
            bool aBit = (a & 1), bBit = (b & 1);

            if ((aBit | bBit) ^ cBit) {
                if (cBit && !(aBit & bBit)) {
                    numFlips++;
                } else if (!cBit) {
                    if (aBit ^ bBit) {
                        numFlips++;
                    } else {
                        numFlips += 2;
                    }
                }
            }

            c >>= 1;
            a >>= 1;
            b >>= 1;
        }

        return numFlips;
    }
};
