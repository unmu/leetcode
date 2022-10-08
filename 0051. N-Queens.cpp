The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
  
-------------------------------------
  
class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(vector<string> tmp, int row, int col, int n) {
        for (int i = row-1, left = col-1, right = col+1; i >= 0; i--) {
            if (left >= 0) {
                if (tmp[i][left] == 'Q') {
                    return false;
                }
                left--;
            }
            if (right < n) {
                if (tmp[i][right] == 'Q') {
                    return false;
                }
                right++;
            }
            if (tmp[i][col] == 'Q') {
                return false;
            }
        }
        return true;
    }
    
    void dfs(vector<string> &tmp, int row, int &n) {
        if (row == n) {
            ans.push_back(tmp);
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(tmp, row, col, n)) {
                tmp[row][col] = 'Q';
                dfs(tmp, row + 1, n);
                tmp[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> tmp(n, string(n, '.'));
        dfs(tmp, 0, n);
        return ans;
    }
};
