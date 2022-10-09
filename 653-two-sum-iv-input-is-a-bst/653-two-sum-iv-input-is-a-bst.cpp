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
    map<int,int> m;
    bool ans=false;
    int size = 0;
    void dfs(TreeNode* root, int k){
        if(!root) return;
        size++;
        if(m[root->val]>0 and size >=2) ans = true;
        m[k-root->val]++;
        dfs(root->left, k);
        dfs(root->right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};