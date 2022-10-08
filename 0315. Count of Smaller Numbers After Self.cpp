Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104

---------------------------------

class Solution {
public:
    vector<int> ans;
    vector<pair<int, int>> numIdx;
    vector<pair<int, int>> tmp;
    
    void mergeSort(int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = start + (end - start) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        int left = start, right = mid + 1;
        int nRightLessThanLeft = 0, idx = start;
        while (left <= mid && right <= end) {
            if (numIdx[left] <= numIdx[right]) {     //可写成numIdx[left].first <= numIdx[right].first
                ans[numIdx[left].second] += nRightLessThanLeft;
                tmp[idx++] = numIdx[left++];
            } else if (numIdx[left] > numIdx[right]) {
                nRightLessThanLeft++;
                tmp[idx++] = numIdx[right++];
            }
        }
        while (left <= mid) {
            ans[numIdx[left].second] += nRightLessThanLeft;
            tmp[idx++] = numIdx[left++];
        } 
        while (right <= end) {
            tmp[idx++] = numIdx[right++];
        }
        for (int i = start; i <= end; i++) {
            numIdx[i] = tmp[i];
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.resize(n);
        for (int i = 0; i < n; i++) {
            numIdx.push_back({nums[i], i});
            tmp.push_back({nums[i], i});
        }
        mergeSort(0, n - 1);
        return ans;
    }
};
