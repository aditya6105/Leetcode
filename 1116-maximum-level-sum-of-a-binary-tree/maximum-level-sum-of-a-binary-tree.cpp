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
    int maxLevelSum(TreeNode* root){
        long long maxi = root->val;
        int lvl = 1;
        int maxL = 1;
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long s = 0;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();

                s += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(maxi < s){
                maxi = s;
                maxL = lvl;
            }
            lvl++;
        }
        return maxL;
    }
};