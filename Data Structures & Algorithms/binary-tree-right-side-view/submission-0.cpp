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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level = q.size(); 
            TreeNode* rightNode = nullptr;           
            for(int i = 0; i < level; i++){
                TreeNode* curr = q.front();
                q.pop();
                if (curr) {
                    rightNode = curr;
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            if(rightNode) res.push_back(rightNode->val);
        }

        return res;
    }
};
