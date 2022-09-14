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
    int ans = 0;
    map<int,int> m;
    void solve(TreeNode* root){
        if(!root) return;
        m[root->val]++;
        if(!root->left and !root->right){
            int temp = 0;
            for(int i = 1; i<=9; i++){
                if(m[i]%2 != 0){
                    temp++;
                }
            }
            if(temp<=1) ans++;
        }
        solve(root->left);
        solve(root->right);
        m[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root);
        return ans;
    }
};