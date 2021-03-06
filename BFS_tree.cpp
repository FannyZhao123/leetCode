/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

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
    vector<vector<int>> res;
    void bfs (TreeNode* root, int level){
        if (!root) return;
        if (level >= res.size()){
            vector<int> l;
            l.push_back(root->val);
            res.push_back(l);
        }
        else res[level].push_back(root->val);
        bfs(root->left, level+1);
        bfs(root->right, level+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root, 0);
        return res;
    }
};