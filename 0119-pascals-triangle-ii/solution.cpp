class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascal_row = {1};
        for (int cur_row = 1; cur_row <= rowIndex; cur_row++) {
            vector<int> next_row = {1};
            for (int col = 0; col < pascal_row.size() - 1; col++) {
                next_row.push_back(pascal_row[col] + pascal_row[col+1]);
            }
            next_row.push_back(1);
            pascal_row = std::move(next_row);
        }
        return pascal_row;
    }
};
