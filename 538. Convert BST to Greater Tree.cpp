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
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return root;
        RML(root, 0);
        return root;
    }
    int RML(TreeNode* root, int v){
        int r = 0;
        int l = 0;
        if(root->right)
            r = RML(root->right, v);
        if(r == 0)
            root->val += v;
        else 
            root->val+= r;
        //root->val += max(r, v);
        if(root->left)
            l = RML(root->left, root->val);
        if(l == 0)
            return root->val;
        else
            return l;
        return max(root->val, l);
        
    }
};