The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

Example 1:


Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 9

-----------------------------------------

class Solution {
public:
    int ans = 0;
    int tmp[10][10] = {0};
    
    void dfs(int row, int &n) {
        if (row == n) {
            ans++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, n)) {
                tmp[row][col] = 1;
                dfs(row + 1, n);
                tmp[row][col] = 0;
            }
        }
    }
    
    int totalNQueens(int n) {
        dfs(0, n);
        return ans;
    }
    
    bool isSafe(int &row, int &col, int &n) {
        for (int i = row - 1, left = col - 1, right = col + 1; i >= 0; i--) {
            if (tmp[i][col] == 1) {
                return false;
            }
            if (left >= 0) {
                if (tmp[i][left] == 1) {
                    return false;
                }
                left--;
            }
            if (right < n) {
                if (tmp[i][right] == 1) {
                    return false;
                }
                right++;
            }
        }
        return true;
    }
};
