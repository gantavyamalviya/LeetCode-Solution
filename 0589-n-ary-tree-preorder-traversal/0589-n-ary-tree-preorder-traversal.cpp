/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    void solve(Node* root){
        ans.push_back(root->val);
        for(auto x : root->children){
            preorder(x);
        }
    }
    vector<int> preorder(Node* root) {
        if(root) solve(root);
        return ans;
    }
};
    