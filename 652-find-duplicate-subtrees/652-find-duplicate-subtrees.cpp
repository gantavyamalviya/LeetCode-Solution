/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;https://assets.leetcode.com/uploads/2020/08/16/e1.jpg
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<string, int> m;
    vector<TreeNode*> ans;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
    }
    string solve(TreeNode* root){
        if(!root) return "x";
        string l = solve(root->left);
        string r = solve(root->right);
        string temp = to_string(root->val) + " " + l+ " "+r+" ";
        m[temp]++;
        if(m[temp] == 2){
            ans.push_back(root);
        }
        return temp;
    }
};