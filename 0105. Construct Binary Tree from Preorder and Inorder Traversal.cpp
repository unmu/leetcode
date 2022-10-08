Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

--------------------------------------------

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //TreeNode* root = nullptr;
    
    TreeNode * dfs(vector<int> &pre, int pl, int pr, vector<int> &in, int il, int ir) {
        if (pl > pr || il > ir) {
            return nullptr;
        }
        TreeNode *root = new TreeNode();
        root -> val = pre[pl];
        int leftCnt = 0;
        pl++;
        for (int i = il; i <= ir && root -> val != in[i]; i++, leftCnt++) {}
        root -> left = dfs(pre, pl, pl + leftCnt - 1, in, il, il + leftCnt - 1);
        root -> right = dfs(pre, pl + leftCnt, pr, in, il + leftCnt + 1, ir);
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return dfs(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};
