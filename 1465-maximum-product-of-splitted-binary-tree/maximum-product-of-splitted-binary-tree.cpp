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

    long long total = 0;
    long long MOD = 1e9 + 7;

    void totalSum(TreeNode* root){
        if(root == NULL) return;
        
        totalSum(root->left);
        totalSum(root->right);

        total += root->val;
    }

    long long subTreeSum(TreeNode* node, long long &maxProd){
        if(node == NULL) return 0;
        
        long long leftVal = subTreeSum(node->left, maxProd);
        long long rightVal = subTreeSum(node->right, maxProd);

        long long currSum = leftVal + rightVal + node->val;
        long long currProd = currSum * (total - currSum);

        maxProd = max(maxProd, currProd);

        return currSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum(root);
        long long maxProd = 1;
        subTreeSum(root, maxProd);
        return maxProd % MOD;
    }
};