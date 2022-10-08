Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Example 2:

Input: num = 14
Output: false
 

Constraints:

1 <= num <= 2^31 - 1


-----------------------------------------

class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        long long m;
        while (l <= r) {
            m = (r - l) / 2 + l;
            if (m * m == num) {
                return true;
            } else if (m * m > num) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return false;
    }
};
