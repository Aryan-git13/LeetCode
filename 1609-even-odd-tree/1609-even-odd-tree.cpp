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
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL)return false;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            int maxi=INT_MIN;
            int mini=INT_MAX;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();

                if(level%2==0){
                    if(node->val%2==0 || node->val<=maxi)return false;
                    maxi=node->val;
                }
                else{
                    if(node->val%2==1 || node->val>=mini)return false;
                    mini=node->val;
                }

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            level++;
        }
        return true;
    }
};