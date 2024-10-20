class Solution {
public:
    int kthGrammarHelper(int n, int k) {
        if (n == 0 && k == 0) {
            return 0;
        } else if (n == 1) {
            if (k == 0) return 0;
            else return 1;
        }

        if (k < pow(2, n-2)) {
            return kthGrammarHelper(n -1, k);
        } 

        int val = kthGrammarHelper(n -1, k/2);

        if (val == 0) {
            return (k&1)? 1 : 0;
        } else {
            return (k&1)? 0 : 1;
        }

    }
    int kthGrammar(int n, int k) {
        /*
            0
            01
            0110
            01101001
            0110100110010110  

            if (k <= (n/2)) {return s[n-1,k]}
            else {expand(s[n-1,k/2])}
            s [n, k] = s[n]      
        */

        return kthGrammarHelper(n - 1, k - 1);
    }
};
