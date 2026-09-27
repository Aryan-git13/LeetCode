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
    void pre(TreeNode* root,vector<int>& ans){
        if(root==NULL)return;

        if(root->val%2==0){
            if(root->left && root->left->left)ans.push_back(root->left->left->val);
            if(root->left && root->left->right)ans.push_back(root->left->right->val);
            if(root->right && root->right->left)ans.push_back(root->right->left->val);
            if(root->right && root->right->right)ans.push_back(root->right->right->val);
        }
        pre(root->left,ans);
        pre(root->right,ans);
    }
    int sumEvenGrandparent(TreeNode* root) {
        vector<int>ans;
        pre(root,ans);

        int sum=0;
        for( auto& it:ans){
            sum+=it;
        }

        return sum;
    }
};