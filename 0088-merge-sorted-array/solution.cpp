class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int read_idx1 = m - 1, read_idx2 = n - 1;
        int write_idx = m + n - 1;

        while (write_idx >= 0) {
            if (read_idx1 >= 0 && read_idx2 >= 0) {
                if (nums1[read_idx1] >= nums2[read_idx2]) {
                    nums1[write_idx--] = nums1[read_idx1--];
                } else {
                    nums1[write_idx--] = nums2[read_idx2--];
                }
            } else if (read_idx1 == -1 && read_idx2 >= 0) {
                nums1[write_idx--] = nums2[read_idx2--];
            } else {
                nums1[write_idx--] = nums1[read_idx1--];
            }
        }
    }
};
