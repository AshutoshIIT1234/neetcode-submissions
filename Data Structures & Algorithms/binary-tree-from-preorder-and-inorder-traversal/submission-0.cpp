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
    unordered_map<int,int> idx; // val → inorder index

    TreeNode* build(vector<int>& pre, int preL, int preR,
                                      int inL,  int inR) {
        if (preL > preR) return nullptr;

        int rootVal = pre[preL];
        int m = idx[rootVal];         // root's position in inorder
        int leftSize = m - inL;

        TreeNode* root = new TreeNode(rootVal);
        root->left  = build(pre, preL+1,          preL+leftSize, inL,  m-1);
        root->right = build(pre, preL+leftSize+1, preR,          m+1,  inR);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            idx[inorder[i]] = i;

        return build(preorder, 0, n-1, 0, n-1);
    }
};