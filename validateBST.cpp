/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBSTInOrderHelper(TreeNode *p, int& prev) {
        if (!p) return true;
        if (isBSTInOrderHelper(p->left, prev)) {
        if (p->val > prev) {
            prev = p->val;
            return isBSTInOrderHelper(p->right, prev);
        } else {
            return false;
     }
    }
    else {
        return false;
     }
}
    
    bool isValidBST(TreeNode *root) {
        if(root == NULL) return true;
        
        int prev = INT_MIN;
        return isBSTInOrderHelper(root, prev);
    }
};
