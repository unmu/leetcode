Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.

------------------------------------

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int word[26] = {0};
        for (char c : magazine) {
            word[c - 'a']++;
        }
        for (char c : ransomNote) {
            int x = c - 'a';
            word[x]--;
            if (word[x] < 0) {
                return false;
            }
        }
        return true;
    }
};
