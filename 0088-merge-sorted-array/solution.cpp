class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int readIdx1 = m - 1;
        int readIdx2 = n - 1;

        int writeIdx = m + n - 1;

        while (writeIdx >= 0) {
            if (readIdx1 >= 0 && readIdx2 >= 0) {
                if (nums1[readIdx1] > nums2[readIdx2]) {
                    nums1[writeIdx] = nums1[readIdx1];
                    readIdx1--;
                } else if (nums1[readIdx1] <= nums2[readIdx2]) {
                    nums1[writeIdx] = nums2[readIdx2];
                    readIdx2--;
                } 
            } else if (readIdx1 < 0) {
                nums1[writeIdx] = nums2[readIdx2--];
            } else if (readIdx2 < 0) {
                nums1[writeIdx] = nums1[readIdx1--];
            } 
            writeIdx--;
        }

    }
};
