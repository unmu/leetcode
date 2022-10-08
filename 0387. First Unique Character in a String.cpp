Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.

----------------------------------------

class Solution {
public:
    int firstUniqChar(string s) {
        std::ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int charCount[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            charCount[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (charCount[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
