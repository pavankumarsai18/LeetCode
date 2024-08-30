class Solution {
public:
    void push_val(vector<vector<int>>& encoded, int val, int count) {
        if (!encoded.empty() && encoded[encoded.size() - 1][0] == val) {
            encoded[encoded.size() - 1][1] += count;
        } else {
            encoded.push_back({val, count});
        }
    }
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> ans;
        int idx1 = 0, idx2 = 0;
        const int size1 = encoded1.size();
        const int size2 = encoded2.size();

        while (idx1 != size1 || idx2 != size2) {
            if (idx1 != size1 && idx2 != size2) {
                int & count1 = encoded1[idx1][1];
                int & count2 = encoded2[idx2][1];
                int min_common = min(count1, count2);

                int mult = encoded1[idx1][0]*encoded2[idx2][0];
                push_val(ans, mult, min_common);

                count1 -= min_common;
                count2 -= min_common;

                if (count1 == 0) idx1++;
                if (count2 == 0) idx2++;
            } else if (idx1 == size1) {
                push_val(ans, encoded2[idx2][0], encoded2[idx2][1]);
                idx2++;
            } else {
                push_val(ans, encoded1[idx1][0], encoded1[idx1][1]);
                idx1++;
            }
        }
        
        return ans;


    }
};
