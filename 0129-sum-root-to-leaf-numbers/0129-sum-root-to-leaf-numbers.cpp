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
    void preorder(TreeNode* root,vector<string>&ans,string s){
        if(root==NULL)return;
        s.push_back(root->val+'0');
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
            return;
        }

        preorder(root->left,ans,s);
        preorder(root->right,ans,s);
    }
    int sumNumbers(TreeNode* root) {
        string s="";
        vector<string>ans;
        int sum=0;

        preorder(root,ans,s);

        for(int i=0;i<ans.size();i++){
            int num=stoi(ans[i]);
            sum+=num;
        }
        return sum;
    }
};