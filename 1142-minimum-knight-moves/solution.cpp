class Solution {
public:
    int minKnightMoves(int x, int y) {
        // Symmetry for axes
        x = abs(x);
        y = abs(y);
        // Symmetry for diagonal
        if (x < y) {
            swap(x, y);
        }
        if (x == 1 && y == 0) {
            return 3;
        }
        if (x == 2 && y == 2) {
            return 4;
        }
        int delta = x - y;
        if (y > delta) {
            return (int) (delta - 2 * floor((delta - y) / 3.0));
        } else 
        {
            return (int) (delta - 2 * floor((delta - y) / 4.0));
        }
    }
};
