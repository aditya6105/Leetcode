/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
 * };
 */
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*> m;
        vector<TreeNode*> level;

        q.push(root);
        m[root] = NULL;
        while(q.size() > 0){
            int n = q.size();
            level.clear();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node);
                
                if(node->left){
                    m[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    m[node->right] = node;
                    q.push(node->right);
                }
            }
        }

        if(level.size() == 1) return level[0];

        unordered_set<TreeNode*> s(level.begin(), level.end());
        while(s.size() > 1){
            unordered_set<TreeNode*> next;
            for(auto it : s) next.insert(m[it]);
            s = next;
        }

        return *s.begin();
    }
};