class Solution {
long long matrix_size = 0;
unordered_set<int> one_indices;
int num_rows, num_cols;
public:
    Solution(int m, int n) {
        srand(time(0));
        num_rows = m;
        num_cols = n;
        matrix_size = (long long) num_rows * num_cols;
    }
    
    vector<int> flip() {
        int index = (rand() % matrix_size);
        int col_idx, row_idx;
        while (one_indices.find(index) != one_indices.end()) {
            index = (rand() % matrix_size);
        }
        
        col_idx = index % num_cols;
        row_idx = index / num_cols;
        one_indices.insert(index);
        return {row_idx, col_idx};
    }
    
    void reset() {
        one_indices = unordered_set<int>();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
