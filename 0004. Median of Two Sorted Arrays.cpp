Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106



---------------------------------------------

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int len3 = len1 + len2;
        vector<double> nums3(len3);
        int i = 0, j = 0, k = 0;
        while (k < len1 + len2) {
            if (i < len1 && j < len2) {
                if (nums1[i] <= nums2[j]) {
                    nums3[k] = nums1[i];
                    i++;
                } else {
                    nums3[k] = nums2[j];
                    j++;
                }
            } else if (i < len1) {
                nums3[k] = nums1[i];
                i++;
            } else {
                nums3[k] = nums2[j];
                j++;
            }
            k++;
        } 
        if (len3 % 2 == 1) {
            return nums3[len3 / 2];
        } else {
            return (nums3[len3 / 2] + nums3[len3 / 2 - 1]) / 2;
        }
    }
};
