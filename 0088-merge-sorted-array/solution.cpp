class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1, idx2, idx;
        idx1 = m - 1;
        idx2 = n - 1;

        int writeIdx = m + n - 1;
        while (writeIdx >= 0) {
            if (idx1 < 0 && idx2 >= 0) {
                nums1[writeIdx--] = nums2[idx2--];
            } else if (idx2 < 0) {
                nums1[writeIdx--] = nums1[idx1--];
            } else {
                if (nums1[idx1] > nums2[idx2]){
                    nums1[writeIdx--] = nums1[idx1--];
                } else {
                    nums1[writeIdx--] = nums2[idx2--];
                }
            }
        }
    }
};
