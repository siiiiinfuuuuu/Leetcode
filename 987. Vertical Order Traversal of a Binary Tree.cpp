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
class Pos{
public:
    Pos(int a, int b): x(a),y(b){}
    bool operator<(const Pos& p) const{
        return x < p.x || (x == p.x&&y < p.y);
    }
    Pos left(){
        return Pos(x-1,y+1);
    }
    Pos right(){
        return Pos(x+1,y+1);
    }
    int x, y;
};

class Solution {
public:
    map<Pos,vector<int>> treeMap;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        Inorder(root, Pos(0,0));
        int currX = INT_MAX;
        for(auto it = treeMap.begin();  it!=treeMap.end(); it++){
            if(it->first.x!=currX){
                sort(it->second.begin(),it->second.end());
                ans.push_back(it->second);
                currX = it->first.x;
            }
            else{
                sort(it->second.begin(),it->second.end());
                ans.back().insert(ans.back().end(),it->second.begin(),it->second.end());
            }
        }
        return ans;
    }
    void Inorder(TreeNode* root, Pos rPos){
        if(root){
            Inorder(root->left,rPos.left());
            treeMap[rPos].push_back(root->val);
            Inorder(root->right,rPos.right());
        }
    }
};
