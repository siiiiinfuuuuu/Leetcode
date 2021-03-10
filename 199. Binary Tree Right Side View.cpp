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
    vector<int> ans;
    void inorder(TreeNode* root, int level){
        if(root == nullptr)
            return;
        if(ans.size() == level)
            ans.push_back(root->val);
        else
            ans[level] = root->val;
        inorder(root->left, level+1);
        inorder(root->right, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        inorder(root, 0);
        return ans;
    }
};