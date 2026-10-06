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
    void preorder(int& cnt,TreeNode* root,int maxi){
        if(root==NULL)return;
        maxi=max(root->val,maxi);

        if(root->val>=maxi)cnt++;

        preorder(cnt,root->left,maxi);
        preorder(cnt,root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)return 0;

        int cnt=0;
        int maxi=INT_MIN;

        preorder(cnt,root,maxi);
        return cnt;
    }
};