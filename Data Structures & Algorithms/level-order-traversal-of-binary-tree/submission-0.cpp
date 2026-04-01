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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()) {
            vector<int> level;
            int size = queue.size();
            
            for(int i = 0; i < size; i++){
                TreeNode* curr =  queue.front();
                queue.pop();
                if(curr->left) queue.push(curr->left);
                if(curr->right) queue.push(curr->right);
                level.push_back(curr->val);
            }
            res.push_back(level);
        }

        return res;
    }
};
