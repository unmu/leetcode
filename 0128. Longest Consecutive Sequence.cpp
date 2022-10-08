Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
  
----------------------------------------

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        set<int> st;
        for (int x : nums) {
            st.insert(x);
        }
        for (int x : st) {
            if (st.find(x - 1) == st.end()) {
                int cnt = 1, cur = x + 1;
                while (st.find(cur) != st.end()) {
                    cnt++;
                    cur++;
                }
                ans = max(cnt, ans);
            }
        }
        return ans;
    }
};
