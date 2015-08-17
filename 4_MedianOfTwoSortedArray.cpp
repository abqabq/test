class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;
        int size = nums1.size() + nums2.size();
        if (size % 2 == 1) {
            result = findkth(nums1, nums2, 0, 0, size / 2 + 1);
        } else {
            result = (findkth(nums1, nums2, 0, 0, size / 2) + findkth(nums1, nums2, 0, 0, size / 2 + 1)) / 2.0;
        }
        return result;
    }
    
    int findkth(vector<int>& nums1, vector<int>& nums2, int start1, int start2, int k) {
        if (start1 >= nums1.size()) {
            return nums2[start2 + k - 1];
        } else if (start2 >= nums2.size()) {
            return nums1[start1 + k - 1];
        }
        
        if (k == 1) {
            return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
        }
        
        // 比较看两个子数组中位数，谁小就把那个数组的前一半扔了，因为它们一定不是要找的median
        int key1 = start1 + k / 2 - 1 < nums1.size() ? nums1[start1 + k / 2 - 1] : INT_MAX;
        int key2 = start2 + k / 2 - 1 < nums2.size() ? nums2[start2 + k / 2 - 1] : INT_MAX;
        
        return key1 < key2 ? findkth(nums1, nums2, start1 + k / 2, start2, k - k / 2) : 
                             findkth(nums1, nums2, start1, start2 + k / 2, k - k / 2);
    }
};
